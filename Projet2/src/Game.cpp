#include "../include/Game.h"

using namespace std;

//Game::Game() : window(), c(&Keyboard()), spaceship(Spaceship(img->getSpaceship_t())) {}
Game::Game(sf::RenderWindow &window,Resources & res, bool modeGame, list<string>& cheatList) : c(new Armband()), window(&window), rockets(NULL), curPatern(0)
{
	if (c->getStatus() == false)
		c = new Keyboard();

	//Definition du mode de jeu
	this->modeGame = modeGame;
	this->cheatList = cheatList;
	// Chargement de l'objets permettant le chargement des images
	this->res = res;
	//Cr�ation du hub
	gameHub = new GameHub(this->res, window.getSize().x);

	//Create graphical object for the background
	background.setTexture(&this->res.getImg()->getBackground_t());
	background.setTextureRect(sf::IntRect(0, 0, this->window->getSize().x < 8192 ? this->window->getSize().x : 8192, this->window->getSize().y < 768 ? this->window->getSize().y : 768));

	//Set background aspect
	background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	background.setPosition(0, 0);
	
	spaceship = new Spaceship(this->res);
	
	// Activation des codes 
	activateCheat();
	
	
	PaternGeneration();

	//G�n�ration de la musique de fond
	music.setBuffer(this->res.getMusicSnd(1));
	music.setLoop(true);
	music.setVolume(this->res.getConfigXML()->getSettings()->getVolumeMusic());
	music.play();

	//Chargement du son du laser
	laserSnd.setBuffer(this->res.getLaserSnd());
	laserSnd.setVolume(this->res.getConfigXML()->getSettings()->getVolumeSound());
}

void Game::activateCheat() {
	list<string>::iterator it;
	
	// Active les modes de triche
	for (it = cheatList.begin(); it != cheatList.end(); it++) {
		string cheat = (*it);
		cout << "Print cheat : " << cheat << endl;
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
		else if (cheat == "minion") {
			pony = true;
			this->res.getImg()->setEnemy_t("ressources/minionsprite.png");
		}
		else if (cheat.find("uparme") != -1) {
			string substring = cheat.substr(cheat.find("uparme") + 1, cheat.size());
			try {
				cout << "Substring : " << substring << endl;
				int level = stoi(substring);
				spaceship->getWeapon().setLvl(spaceship->getWeapon().getLvl() + 1);

			}
			catch (const std::exception& e) {
				cerr << "Invalid Cheat" << endl;
			}
		}
		else if (cheat == "uplife") {
			//spaceship->setHealth();
		}
		else if (cheat == "uplevel") {

		}
		else if (cheat == "setScore") {

		}
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
	
	// Chargement des diff�rents partern 
	XMLPatern.LoadFile("conf/patern.xml");
	// R�cup�ration du noeud root
	tinyxml2::XMLNode * node = XMLPatern.RootElement();

	if (XMLPatern.ErrorID() == 0) {
		if (node != NULL) {
			// R�cup�ration du nombre de patern
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
				// G�n�ration en fonction du nombre de patern disponible une liste al�atoire de patern d'ennemi
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
	while (!endGame && spaceship->isAlive())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				endGame = true;
				music.stop();
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
		// Mode de jeu Standard
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
				int displayEnemy = (int)(window->getSize().y / 100);
				int delta = ((int)window->getSize().y - (displayEnemy-1) * 100) / (displayEnemy-1);
				addEnemies(patern[curPatern].spawn(res, typeEnemy, pony, displayEnemy, delta));
				curPatern += patern[curPatern].next();
			}
		}
		// Mode de jeu Endless
		else {
			if (patern.size() != 0 && curPatern < patern.size()) {
				if (enemies.empty()) {
					PaternGeneration();

					// On g�n�re un enemi al�atoire
					curPatern = 0;
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
					int displayEnemy = (int)(window->getSize().y / 100);
					int delta = ((int)window->getSize().y - (displayEnemy - 1) * 100) / (displayEnemy - 1);
					addEnemies(patern[curPatern].spawn(res, typeEnemy, pony, displayEnemy, delta));
					compteurPatern += 1;
					curPatern += 1;
				}
			}
			else {
				if (compteurPatern == 10) {

					// On g�n�re un nombre al�atoire pour faire pop un boss
					int random;
					if (curLevel == 0)
						random = 0;
					else if (curLevel == 1) {
						random = 1;
					}
					else {
						random = rand() % curLevel + 1;
					}
					random = rand() % this->res.getConfigXML()->getBossList().size();
					TypeEnemy * type = this->res.getConfigXML()->getBossList().at(random);
					addBoss(type);
					compteurPatern = 0;
					popBoss = true;
					curLevel += 1;
				}
				curPatern =0;
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

		//Contr�le des ennemis
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
		//Contr�le du boss
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

		//Contr�le des animations
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

		//Mise � jour du Hub
		gameHub->updateHub(window, spaceship, boss, score);

		window->display();
	}
	//After the death of player, enter is name
	gameHub->setPlayerPseudo(window, res.getImg()->getBackground_t(),score,c,res);
	if(!modeGame)
		this->res.getConfigXML()->CreateScore(this->score, gameHub->getPlayerPseudo(),"Normal");
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
		background.setTextureRect(sf::IntRect(background.getTextureRect().left + 2, 0, this->window->getSize().x < 8192 ? this->window->getSize().x : 8192, this->window->getSize().y < 768 ? this->window->getSize().y : 768));
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
	this->boss = new Boss(type, res,pos);
}

void Game::addBoss(TypeEnemy * type){

	//Boss::Boss(int life, int dommage, int LaserSpeed, int speed,int rate, sf::Texture& texture, sf::Vector2f pos)
	sf::Vector2f pos(window->getSize().x, window->getSize().y / 2);
	this->boss = new Boss(type, res, pos);
}

void Game::addLasers(vector<Laser*> &l)
{
	if (laserSnd.getStatus() != laserSnd.Playing && l.size()>0)
		laserSnd.play();

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
	patern.~vector();
	if (boss != NULL) {
		delete boss;
	}
	
	delete spaceship;
	c->~Control();
}