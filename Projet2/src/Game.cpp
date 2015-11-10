#include "../include/Game.h"

using namespace std;

//Game::Game() : window(), c(&Keyboard()), spaceship(Spaceship(img->getSpaceship_t())) {}

Game::Game(sf::RenderWindow &window,Resources & res, bool modeGame, string cheat) : c(new Armband()), window(&window), rockets(NULL), curPatern(0)
{
	if (c->getStatus() == false)
		c = new Keyboard();
	// Chargement de la texture pour les textes 
	arial.loadFromFile("ressources/arial.ttf");

	

	//Definition du mode de jeu
	this->modeGame = modeGame;

	// Chargement de l'objets permettant le chargement des images
	this->res = res;
	//Création du hub
	gameHub = new GameHub();

	//Create graphical object for the background
	background.setTexture(&this->res.getImg()->getBackground_t());
	background.setTextureRect(sf::IntRect(0, 0, this->window->getSize().x, this->window->getSize().y));

	//Set background aspect
	background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	background.setPosition(0, 0);
	
	spaceship = new Spaceship(this->res.getImg()->getSpaceship_t(), this->res.getImg()->getExplosion_t(),this->res.getExplosionSnd());
	
	// Activation des codes 
	activateCheat(cheat);
	
	
	PaternGeneration();

	//Génération de la musique de fond
	music.setBuffer(res.getMusicSnd(1));
	music.setLoop(true);
	music.play();
}

void Game::activateCheat(string cheat) {
	if (cheat == "grave") {
		spaceship->getWeapon().setLvl(5);
		curLevel = 11;
		spaceship->setHealth(150000, true);
		res.getImg()->setSpaceship_t("ressources/grave.png");
	}
	else if (cheat == "mylittlepony") {
		pony = true;
		this->res.getImg()->setEnemy_t("ressources/ponysprite.png");
	}
	else if (cheat == "reset"){

	}
	else if (cheat == "") {

	}
}

void Game::PaternGeneration() {

	curPatern = 0;
	std::cout << "cur patern :" << curPatern << endl;
	nbPaternAvailable = 0;
	popBoss = false;
 	
	std::cout << "NB bullets" << rockets.size() << endl;
	std::cout << "NB enemies" << enemies.size() << endl;
	std::cout << "NB lasers" << rockets.size() << endl;
	
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
			patern.clear();
			curPatern = 0;
			if (!modeGame) {
				// Génération en fonction du nombre de patern disponible une liste aléatoire de patern d'ennemi
				for (int i = 0; i < res.getConfigXML()->getLevelList().at(curLevel)->getNbPatern(); i++) {
					int number = rand() % nbPaternAvailable + 1;
					patern.push_back(Patern(XMLPatern, number));
				}
			}
			else {
				patern.clear();
				int number = rand() % nbPaternAvailable + 1;
				patern.push_back(Patern(XMLPatern, number));
			}
			
		}
	}
	else {
		// SI une erreur on ferme le programe
		window->close();
		std::cerr << "Failed to open the file patern.xml in conf's folder. Error ID : " << XMLPatern.ErrorID() << endl;
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

	while (!endGame && spaceship->isAlive())
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

		window->clear();
		window->draw(background);

		//Dessiner le player
		window->draw(getSpaceship()->getSprite());
		//Dessiner l'explosion du player si existant
		if(getSpaceship()->getExplosionSprite().getTexture() != NULL)
			window->draw(getSpaceship()->getExplosionSprite());

		moveBackground();
		collision();
		control();
		if (!modeGame) {
			if (patern.size() != 0 && curPatern < patern.size())
			{
				int random;
				do {

					if (curLevel == 0)
						random = 0;
					else if (curLevel == 1) {
						random = 1;
					}
					else {
						random = rand() % curLevel + 1;
					}
				} while (random > this->res.getConfigXML()->getTypeEnemyList().size());
				TypeEnemy * typeEnemy = this->res.getConfigXML()->getTypeEnemyList().at(random);
				addEnemies(patern[curPatern].spawn(this->res.getImg()->getEnemy_t(), this->res.getImg()->getExplosion_t(),res.getExplosionSnd(), typeEnemy, pony));
				curPatern += patern[curPatern].next();
			}
		}
		else {
			if (patern.size() != 0 && curPatern < patern.size()) {
				if (enemies.empty()) {
					PaternGeneration();
					curPatern = 0;
					int random;
					do {
						random = rand() % this->res.getConfigXML()->getTypeEnemyList().size();
					} while (random > this->res.getConfigXML()->getTypeEnemyList().size());
					TypeEnemy * typeEnemy = this->res.getConfigXML()->getTypeEnemyList().at(random);
					addEnemies(patern[curPatern].spawn(this->res.getImg()->getEnemy_t(), this->res.getImg()->getExplosion_t(),res.getExplosionSnd(), typeEnemy, pony));
					compteurPatern += 1;
					curPatern += 1;
				}
			}
			else {
				if (compteurPatern == 10) {
					int random;
					random = rand() % this->res.getConfigXML()->getBossList().size();
					TypeEnemy * type = this->res.getConfigXML()->getBossList().at(random);
					addBoss(type);
					compteurPatern = 0;
					popBoss = true;
				}
				curPatern =0;
				//patern.clear();
			}
		}
		

		if ((curPatern == patern.size() && enemies.size() == 0) && !popBoss && !modeGame) {
			addBoss();
			popBoss = true;
		}
		if (c->quit())
		{
			endGame = true;
		}

		//Contrôle des ennemis
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies.at(i)->isAlive())
			{
				if (enemies.at(i)->getHealth() > 0)
					addLasers(enemies.at(i)->shoot(this->res.getImg()->getLaser_t())); //Tir des ennemis

				window->draw(enemies.at(i)->getSprite());
				//Dessiner le sprite de l'explosion si existant
				if (enemies.at(i)->getExplosionSprite().getTexture() != NULL)
					window->draw(enemies.at(i)->getExplosionSprite());

				enemies.at(i)->move();
			}
			else
			{
				score += enemies.at(i)->getScore();
				if (rand() % 10 == 0)
				{
					sf::Vector2f pos = sf::Vector2f(enemies.at(i)->getSprite().getPosition().x + enemies.at(i)->getSprite().getGlobalBounds().width / 2, enemies.at(i)->getSprite().getPosition().y + enemies.at(i)->getSprite().getGlobalBounds().height / 2);
					bonus.push_back(new Bonus(res.getImg()->getBonus_t(), pos));
				}
				delete enemies.at(i);
				enemies.erase(enemies.begin() + i);
			}
		}
		//Contrôle du boss
		if (popBoss)
		{
			if (boss != NULL)
			{
				if (boss->isAlive())
				{
					if (boss->getHealth() > 0)
						addLasers(this->boss->shoot(this->res.getImg()->getLaser_t())); //Tir du boss

					window->draw(boss->getSprite());

					if (boss->getExplosionSprite().getTexture() != NULL)
						window->draw(boss->getExplosionSprite());

					this->boss->move(getSpaceship()->getSprite());
				}
				else
				{
					score += boss->getScore();
					delete boss;
					boss = NULL;
					gameHub->resetHub();
					curLevel += 1;
					this->spaceship->setHealth(500, false);
				}
			}
			else
			{
				PaternGeneration();
			}
		}

		//Contrôle des animations
		if (fpsCount >= fpsSwitch)
		{
			getSpaceship()->switchFps();
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
			for (int i = 0; i < bonus.size(); i++)
			{
				getBonus().at(i)->switchFps();
			}
			fpsCount = 0;
		}
		else
			fpsCount += clk.restart().asMilliseconds();

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
		for (int i = 0; i < bonus.size(); i++)
		{
			getBonus().at(i)->move();
			window->draw(getBonus().at(i)->getSprite());
		}

		//Mise à jour du Hub
		gameHub->updateHub(window, spaceship, boss, score);

		window->display();
	}

	//After the death of player, enter is name
	gameHub->setPlayerPseudo(window, res.getImg()->getBackground_t(),score,c);
	if(!modeGame)
		this->res.getConfigXML()->CreateScore(this->score, gameHub->getPlayerPseudo(),"Normal" );
	else
		this->res.getConfigXML()->CreateScore(this->score, gameHub->getPlayerPseudo(), "Endless");
}

Spaceship *Game::getSpaceship()
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

vector<Bonus*> &Game::getBonus(){
	return bonus;
}

void Game::moveBackground()
{
	if (background.getTextureRect().left + background.getTextureRect().width >= this->res.getImg()->getBackground_t().getSize().x)
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
	
	//Boss::Boss(int life, int dommage, int LaserSpeed, int speed,int rate, sf::Texture& texture, sf::Vector2f pos)
	TypeEnemy * type = res.getConfigXML()->getBossList().at(curLevel);
	sf::Vector2f pos(window->getSize().x, window->getSize().y / 2);
	this->boss = new Boss(type, res.getImg()->getBoss_t(),res.getImg()->getExplosion_t(),res.getExplosionSnd(),pos);
}

void Game::addBoss(TypeEnemy * type){

	//Boss::Boss(int life, int dommage, int LaserSpeed, int speed,int rate, sf::Texture& texture, sf::Vector2f pos)
	sf::Vector2f pos(window->getSize().x, window->getSize().y / 2);
	this->boss = new Boss(type, res.getImg()->getBoss_t(), res.getImg()->getExplosion_t(),res.getExplosionSnd(), pos);
}

void Game::addLasers(vector<Laser*> &l)
{
	for (int i = 0; i < l.size(); i++)
		this->lasers.push_back(l[i]);
}

void Game::control()
{
	if (spaceship->getHealth() > 0)
	{
		addRockets(c->shoot(this->res.getImg()->getRocket_t(), spaceship));
		c->move(spaceship);
		c->runHub();
	}
}

void Game::collision()
{
	//Collision between player rockets and enemies
	for (int i = 0; i < rockets.size(); i++)
	{
		if (rockets[i]->getSprite().getPosition().x > window->getSize().x)
			rockets.erase(rockets.begin() + i);
		else
			if (boss != NULL)
			{
				if (rockets.at(i)->getSprite().getPosition().x + rockets.at(i)->getSprite().getGlobalBounds().width > boss->getSprite().getPosition().x &&
					rockets.at(i)->getSprite().getPosition().x < boss->getSprite().getPosition().x + boss->getSprite().getGlobalBounds().width &&
					rockets.at(i)->getSprite().getPosition().y + rockets.at(i)->getSprite().getGlobalBounds().height > boss->getSprite().getPosition().y &&
					rockets.at(i)->getSprite().getPosition().y < boss->getSprite().getPosition().y + boss->getSprite().getGlobalBounds().height)
				{
					boss->takeDommage(rockets.at(i)->getDommages());
					delete rockets.at(i);
					rockets.erase(rockets.begin() + i);
				}
			}
			else
			{
				for (int j = 0; j < enemies.size(); j++)
				{
					if (rockets.at(i)->getSprite().getPosition().x + rockets.at(i)->getSprite().getGlobalBounds().width > enemies.at(j)->getSprite().getPosition().x &&
						rockets.at(i)->getSprite().getPosition().x < enemies.at(j)->getSprite().getPosition().x + enemies.at(j)->getSprite().getGlobalBounds().width &&
						rockets.at(i)->getSprite().getPosition().y + rockets.at(i)->getSprite().getGlobalBounds().height > enemies.at(j)->getSprite().getPosition().y &&
						rockets.at(i)->getSprite().getPosition().y < enemies.at(j)->getSprite().getPosition().y + enemies.at(j)->getSprite().getGlobalBounds().height)
					{
						enemies.at(j)->takeDommage(rockets.at(i)->getDommages());
						delete rockets.at(i);
						rockets.erase(rockets.begin() + i);
						break;
					}
				}
			}
	}

	//Enemies lasers collision
	for (int i = 0; i < lasers.size(); i++)
	{
		if (lasers.at(i)->getSprite().getPosition().x + lasers.at(i)->getSprite().getGlobalBounds().width < 0)
		{
			delete lasers.at(i);
			lasers.erase(lasers.begin() + i);
		}
		else if (lasers.at(i)->getSprite().getPosition().x + lasers.at(i)->getSprite().getGlobalBounds().width > spaceship->getSprite().getPosition().x &&
			lasers.at(i)->getSprite().getPosition().x < spaceship->getSprite().getPosition().x + spaceship->getSprite().getGlobalBounds().width &&
			lasers.at(i)->getSprite().getPosition().y + lasers.at(i)->getSprite().getGlobalBounds().height > spaceship->getSprite().getPosition().y &&
			lasers.at(i)->getSprite().getPosition().y < spaceship->getSprite().getPosition().y + spaceship->getSprite().getGlobalBounds().height)
		{
			spaceship->takeDommage(lasers.at(i)->getDommages());
			delete lasers.at(i);
			lasers.erase(lasers.begin() + i);
		}
	}

	//Bonus collision
	for (int i = 0; i < bonus.size(); i++)
	{
		if (bonus.at(i)->getSprite().getPosition().x + bonus.at(i)->getSprite().getGlobalBounds().width < 0)
		{
			delete bonus.at(i);
			bonus.erase(bonus.begin() + i);
		}
		else if (bonus.at(i)->getSprite().getPosition().x + bonus.at(i)->getSprite().getGlobalBounds().width > spaceship->getSprite().getPosition().x &&
			bonus.at(i)->getSprite().getPosition().x < spaceship->getSprite().getPosition().x + spaceship->getSprite().getGlobalBounds().width &&
			bonus.at(i)->getSprite().getPosition().y + bonus.at(i)->getSprite().getGlobalBounds().height > spaceship->getSprite().getPosition().y &&
			bonus.at(i)->getSprite().getPosition().y < spaceship->getSprite().getPosition().y + spaceship->getSprite().getGlobalBounds().height)
		{
			spaceship->getWeapon().setLvl(spaceship->getWeapon().getLvl() + bonus.at(i)->getEffect());
			delete bonus.at(i);
			bonus.erase(bonus.begin() + i);
		}
	}

	//Enemies collisions
	if (boss != NULL)
	{
		if (boss->getHealth() > 0 &&
			boss->getSprite().getPosition().x + boss->getSprite().getGlobalBounds().width > spaceship->getSprite().getPosition().x &&
			boss->getSprite().getPosition().x < spaceship->getSprite().getPosition().x + spaceship->getSprite().getGlobalBounds().width &&
			boss->getSprite().getPosition().y + boss->getSprite().getGlobalBounds().height > spaceship->getSprite().getPosition().y &&
			boss->getSprite().getPosition().y < spaceship->getSprite().getPosition().y + spaceship->getSprite().getGlobalBounds().height)
		{
			spaceship->takeDommage(boss->getHealth());
		}
	}
	else
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies.at(i)->getSprite().getPosition().x + enemies.at(i)->getSprite().getGlobalBounds().width < 0)
			{
				delete enemies.at(i);
				enemies.erase(enemies.begin() + i);
			}
			else if (enemies.at(i)->getHealth() > 0 &&
				enemies.at(i)->getSprite().getPosition().x + enemies.at(i)->getSprite().getGlobalBounds().width > spaceship->getSprite().getPosition().x &&
				enemies.at(i)->getSprite().getPosition().x < spaceship->getSprite().getPosition().x + spaceship->getSprite().getGlobalBounds().width &&
				enemies.at(i)->getSprite().getPosition().y + enemies.at(i)->getSprite().getGlobalBounds().height > spaceship->getSprite().getPosition().y &&
				enemies.at(i)->getSprite().getPosition().y < spaceship->getSprite().getPosition().y + spaceship->getSprite().getGlobalBounds().height)
			{
				spaceship->takeDommage(enemies.at(i)->getHealth());
				enemies.at(i)->takeDommage(enemies.at(i)->getHealth());
			}
		}
	}

	//Player collision with the border of the screen
	if (spaceship->getSprite().getPosition().x < 0)
	{
		spaceship->getSprite().setPosition(0, spaceship->getSprite().getPosition().y);
	}
	else if (spaceship->getSprite().getPosition().x + spaceship->getSprite().getGlobalBounds().width > window->getSize().x)
	{
		spaceship->getSprite().setPosition(window->getSize().x - spaceship->getSprite().getGlobalBounds().width, spaceship->getSprite().getPosition().y);
	}
	if (spaceship->getSprite().getPosition().y < 0)
	{
		spaceship->getSprite().setPosition(spaceship->getSprite().getPosition().x, 0);   
	}
	else if (spaceship->getSprite().getPosition().y + spaceship->getSprite().getGlobalBounds().height > window->getSize().y)
	{
		spaceship->getSprite().setPosition(spaceship->getSprite().getPosition().x, window->getSize().y - spaceship->getSprite().getGlobalBounds().height);
	}
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
	if (boss != NULL) {
		delete boss;
	}
	
	delete spaceship;
	c->~Control();
}