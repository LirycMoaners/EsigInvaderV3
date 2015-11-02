#include "../include/Game.h"

Game::Game() : window(), c(&Keyboard()), spaceship(Spaceship(img->getSpaceship_t())) {}

Game::Game(sf::RenderWindow &window) : c(new Armband()), window(&window), rockets(NULL), curPatern(0)
{
	if (c->getStatus() == false)
		c = new Keyboard();
	// Chargement de la texture pour les textes 
	arial.loadFromFile("ressources/arial.ttf");
	// Chargement de l'objets permettant le chargement des images
	img = new Img();

	//Create graphical object for the background
	background.setTexture(&img->getBackground_t());
	background.setTextureRect(sf::IntRect(0, 0, this->window->getSize().x, this->window->getSize().y));

	//Set background aspect
	background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	background.setPosition(0, 0);
	
	spaceship = Spaceship(img->getSpaceship_t());
	// Chargement des différents fichiers de configuration
	loadingConfiguration();

	// Chargement des différents partern 
	XMLPatern.LoadFile("conf/patern.xml");
	// Récupération du noeud root
	tinyxml2::XMLNode * node = XMLPatern.RootElement();
	
	if (XMLPatern.ErrorID() == 0) {
		if (node != NULL) {
			// Récupération du nombre de patern
			//nbPaternAvailable = stoi(node->FirstChildElement("NbPaternAvailable")->GetText());
			tinyxml2::XMLElement * pattern = node->FirstChildElement("patern");
			do {
				if (pattern != NULL) {
					nbPaternAvailable += 1;
					pattern = pattern->NextSiblingElement("patern");
				}
			} while (pattern != NULL);
			std::cout << "NB pattern available : " << nbPaternAvailable << endl;
			// Génération en fonction du nombre de patern disponible une liste aléatoire de patern d'ennemi
			for (int i = 0; i < levelList.at(curLevel)->getNbPatern(); i++) {
				int number = rand() % nbPaternAvailable + 1;
				patern.push_back(Patern(XMLPatern, number));
			}
		}
	}
	else {
		// SI une erreur on ferme le programe
		window.close();
		std::cerr << "Failed to open the file patern.xml in conf's folder. Error ID : " << XMLPatern.ErrorID() << endl;
	}
	
}

void Game::loadingConfiguration() {
	tinyxml2::XMLDocument xmlLevel;
	// Chargement de la configuration des niveaux
	xmlLevel.LoadFile("conf/conflevel.xml");
	if (xmlLevel.ErrorID() == 0) {
		bool read = false;
		tinyxml2::XMLNode * node = xmlLevel.RootElement();
		// Récupération de la première balise Level
		tinyxml2::XMLElement * levelResult = node->FirstChildElement("Levels")->FirstChildElement("Level");
			while (levelResult != NULL) {
				int nbPattern;
				string background;
				// Récupération du Nb de patern permettant le niveau
				nbPattern = stoi(levelResult->FirstChildElement("NbPatern")->GetText());
				background = levelResult->FirstChildElement("UrlImageBackground")->GetText();
				levelList.push_back(new Level(nbPattern, background));
				// Passage à la balise Level Suivante
				levelResult = levelResult->NextSiblingElement("Level");
		}
	}
	else {
		std::cout << "Error searching lvl" << std::endl;
		std::cerr << "Failed to open the file conflevel.xml in conf's folder. Error ID : " << xmlLevel.ErrorID() << endl;
		window->close();
	}

	// Chargement de la configuration des ennemies
	tinyxml2::XMLDocument xmlEnemy;
	xmlEnemy.LoadFile("conf/confenemy.xml");
	if (xmlEnemy.ErrorID() == 0) {
		bool read = false;
		tinyxml2::XMLNode * nodeEnemy = xmlEnemy.RootElement();
		// Récupération de la première balise Enemy disponible;
		tinyxml2::XMLElement * levelEnemy = nodeEnemy->FirstChildElement("Enemies")->FirstChildElement("Enemy");
		while (levelEnemy) {
			// Récupération et conversion des champs 
			int life = stoi(levelEnemy->FirstChildElement("Life")->GetText());
			int dommage = stoi(levelEnemy->FirstChildElement("Dommage")->GetText());
			int speedEnemyFire = stoi(levelEnemy->FirstChildElement("LaserSpeed")->GetText());
			int speed = stoi(levelEnemy->FirstChildElement("Speed")->GetText());
			int rate = stoi(levelEnemy->FirstChildElement("Rate")->GetText());
			// Ajout du type d'ennemi dans la liste
			typeList.push_back(new TypeEnemy(life, dommage, speedEnemyFire, speed));
			// Passage à la balise suivante
			levelEnemy = levelEnemy->NextSiblingElement("Enemy");
		}
	}
	else {
		std::cout << "Error searching enemies" << std::endl;
		std::cerr << "Failed to open the file confenemy.xml in conf's folder. Error ID : " << xmlEnemy.ErrorID() << endl;
		window->close();
	}
	// Chargement de la configuration des boss 
	tinyxml2::XMLDocument xmlboss;
	xmlboss.LoadFile("conf/confboss.xml");
	if (xmlboss.ErrorID() == 0) {
		bool read = false;
		tinyxml2::XMLNode * nodeEnemy = xmlboss.RootElement();
		// Positionnement de l'element à la première balise Boss disponible;
		tinyxml2::XMLElement * levelBoss = nodeEnemy->FirstChildElement("Bosses")->FirstChildElement("Boss");
		while (levelBoss) {
			// Récupération de tout les champs disponible
			int life = stoi(levelBoss->FirstChildElement("Life")->GetText());
			int dommage = stoi(levelBoss->FirstChildElement("Dommage")->GetText());
			int speedEnemyFire = stoi(levelBoss->FirstChildElement("LaserSpeed")->GetText());
			int speed = stoi(levelBoss->FirstChildElement("Speed")->GetText());
			int rate = stoi(levelBoss->FirstChildElement("Rate")->GetText());
			// Ajout d'un nouveau boss à la liste 
			sf::Vector2f pos(window->getSize().x - img->getBoss_t().getSize().x, window->getSize().y/2);
			bossList.push_back(new Boss(life, dommage, speed,speedEnemyFire,rate,img->getBoss_t(), pos));
			// Passage à la balise suivante
			levelBoss = levelBoss->NextSiblingElement("Boss");
		}
	}
	else {
		std::cout << "Error searching enemies" << std::endl;
		std::cerr << "Failed to open the file confboss.xml in conf's folder. Error ID : " << xmlboss.ErrorID() << endl;
		window->close();
	}

}


void Game::runGame()
{
	sf::Clock clk;
	int fpsCount = 0;
	int fpsSwitch = 200;
	bool endGame = false;

	sf::Text quit;
	quit.setString("Quit");
	quit.setFont(arial);
	quit.setCharacterSize(48);
	quit.setColor(sf::Color(255, 255, 255, 255));

	while (!endGame)
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				endGame = true;
				window->close();
			}
		}

		moveBackground();
		collision();
		control();

		if (patern.size() != 0 && curPatern < patern.size())
		{
			addEnemies(patern[curPatern].spawn(img->getEnemy_t()));
			curPatern += patern[curPatern].next();
		}

		if ((curPatern == patern.size() && enemies.size() == 0) && !popBoss) {
			addBoss();
			popBoss = true;
		}
		if (c->quit())
		{
			endGame = true;
		}

		for (int i = 0; i < enemies.size(); i++)
			addLasers(enemies.at(i)->shoot(img->getLaser_t()));
		if (popBoss) {
			addLasers(this->boss->shoot(img->getLaser_t()));
		}
		if (fpsCount >= fpsSwitch)
		{
			getSpaceship().switchFps();
			for (int i = 0; i < getRockets().size(); i++)
			{
				getRockets().at(i)->switchFps();
			}
			for (int i = 0; i < getEnemies().size(); i++)
			{
				getEnemies().at(i)->switchFps();
			}
			for (int i = 0; i < getLasers().size(); i++)
			{
				getLasers().at(i)->switchFps();
			}
			fpsCount = 0;
		}
		else
			fpsCount += clk.restart().asMilliseconds();

		window->clear();
		window->draw(background);
		for (int i = 0; i < getRockets().size(); i++)
		{
			getRockets().at(i)->move();
			window->draw(getRockets().at(i)->getSprite());
		}
		for (int i = 0; i < getLasers().size(); i++)
		{
			getLasers().at(i)->move();
			window->draw(getLasers().at(i)->getSprite());
		}
		for (int i = 0; i < getEnemies().size(); i++)
		{
			getEnemies().at(i)->move();
			window->draw(getEnemies().at(i)->getSprite());
		}

		if ((curPatern == patern.size() && enemies.size() == 0)) {
			this->boss->move(getSpaceship().getSprite());
			window->draw(boss->getSprite());
		}
		window->draw(getSpaceship().getSprite());
		window->display();
	}
}

Spaceship &Game::getSpaceship()
{
	return spaceship;
}

vector<Rocket*> &Game::getRockets()
{
	return rockets;
}

vector<Enemy*> &Game::getEnemies()
{
	return enemies;
}

vector<Laser*> &Game::getLasers()
{
	return lasers;
}

void Game::moveBackground()
{
	if (background.getTextureRect().left + background.getTextureRect().width >= img->getBackground_t().getSize().x)
		background.setTextureRect(sf::IntRect(0, 0, window->getSize().x, window->getSize().y));
	else
		background.setTextureRect(sf::IntRect(background.getTextureRect().left + 2, 0, window->getSize().x, window->getSize().y));
}

void Game::addRockets(vector<Rocket*> &r)
{
	for (int i = 0; i < r.size(); i++)
		this->rockets.push_back(r[i]);
}

void Game::addEnemies(vector<Enemy*> &e)
{
	for (int i = 0; i < e.size(); i++)
		this->enemies.push_back(e[i]);
}

void Game::addBoss() {
	
	this->boss = bossList.at(curLevel);
}

void Game::addLasers(vector<Laser*> &l)
{
	for (int i = 0; i < l.size(); i++)
		this->lasers.push_back(l[i]);
}

void Game::control()
{
	addRockets(c->shoot(img->getRocket_t(), spaceship));
	c->move(spaceship);
	c->runHub();
}

void Game::collision()
{
	for (int i = 0; i < rockets.size(); i++)
	{
		if (rockets[i]->getSprite().getPosition().x > window->getSize().x)
			rockets.erase(rockets.begin() + i);
		else
			for (int j = 0; j < enemies.size(); j++)
				if (rockets.at(i)->getSprite().getPosition().x + rockets.at(i)->getSprite().getGlobalBounds().width > enemies[j]->getSprite().getPosition().x &&
					rockets.at(i)->getSprite().getPosition().y + rockets.at(i)->getSprite().getGlobalBounds().height > enemies[j]->getSprite().getPosition().y &&
					rockets.at(i)->getSprite().getPosition().y < enemies[j]->getSprite().getPosition().y + enemies[j]->getSprite().getGlobalBounds().height)
				{
					enemies.erase(enemies.begin() + j);
					rockets.erase(rockets.begin() + i);
					break;
				}
	}

	for (int i = 0; i < lasers.size(); i++)
		if (lasers.at(i)->getSprite().getPosition().x + lasers.at(i)->getSprite().getGlobalBounds().width < 0)
			lasers.erase(lasers.begin() + i);

	for (int i = 0; i < enemies.size(); i++)
		if (enemies[i]->getSprite().getPosition().x + enemies[i]->getSprite().getGlobalBounds().width < 0)
			enemies.erase(enemies.begin() + i);

	if (spaceship.getSprite().getPosition().x < 0)
		spaceship.getSprite().setPosition(0, spaceship.getSprite().getPosition().y);
	else if (spaceship.getSprite().getPosition().x + spaceship.getSprite().getTextureRect().width > window->getSize().x)
		spaceship.getSprite().setPosition(window->getSize().x - spaceship.getSprite().getTextureRect().width, spaceship.getSprite().getPosition().y);
	
	if (spaceship.getSprite().getPosition().y < 0)
		spaceship.getSprite().setPosition(spaceship.getSprite().getPosition().x, 0);
	else if (spaceship.getSprite().getPosition().y + spaceship.getSprite().getTextureRect().height > window->getSize().y)
		spaceship.getSprite().setPosition(spaceship.getSprite().getPosition().x, window->getSize().y - spaceship.getSprite().getTextureRect().height);
}

Game::~Game()
{
	for (int i = 0; i < rockets.size(); i++)
	{
		delete rockets.at(i);
	}
	rockets.~vector();
	for (int i = 0; i < lasers.size(); i++)
	{
		delete lasers.at(i);
	}
	lasers.~vector();
	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies.at(i);
	}
	enemies.~vector();
	/*for (int i = 0; i < patern.size(); i++)
	{
		delete patern.at(i);
	}*/
	patern.~vector();
	spaceship.~Spaceship();
	c->~Control();
}