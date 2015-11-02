#include "..\include\ConfigXml.h"



ConfigXml::ConfigXml()
{
	loadingConfiguration();
}

vector<Level*> ConfigXml::getLevelList() {
	return levelList;
}
vector<TypeEnemy*> ConfigXml::getTypeEnemyList() {
	return typeList;
}
vector<TypeEnemy *> ConfigXml::getBossList() {
	return bossList;
}


ConfigXml::~ConfigXml()
{
	for (int i = 0; i< levelList.size(); i++) {
		delete levelList.at(i);

	}

	for (int i = 0; i< bossList.size(); i++) {
		delete bossList.at(i);

	}

	for (int i = 0; i< typeList.size(); i++) {
		delete typeList.at(i);

	}
}

void ConfigXml::loadingConfigurationLevel() {
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
		exit(EXIT_FAILURE);
	}
}

void ConfigXml::loadingConfigurationTypeEnemy() {
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
			int LaserSpeed = stoi(levelEnemy->FirstChildElement("LaserSpeed")->GetText());
			int speed = stoi(levelEnemy->FirstChildElement("Speed")->GetText());
			int rate = stoi(levelEnemy->FirstChildElement("Rate")->GetText());
			// Ajout du type d'ennemi dans la liste
			typeList.push_back(new TypeEnemy(life, dommage, LaserSpeed, speed, rate));
			// Passage à la balise suivante
			levelEnemy = levelEnemy->NextSiblingElement("Enemy");
		}
	}
	else {
		std::cout << "Error searching enemies" << std::endl;
		std::cerr << "Failed to open the file confenemy.xml in conf's folder. Error ID : " << xmlEnemy.ErrorID() << endl;
		exit(EXIT_FAILURE);
	}
}
void ConfigXml::loadingConfigurationBoss() {
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
			//sf::Vector2f pos(window->getSize().x - img->getBoss_t().getSize().x, window->getSize().y / 2);
			bossList.push_back(new TypeEnemy(life, dommage, speed, speedEnemyFire, rate));
			// Passage à la balise suivante
			levelBoss = levelBoss->NextSiblingElement("Boss");
		}
	}
	else {
		std::cout << "Error searching enemies" << std::endl;
		std::cerr << "Failed to open the file confboss.xml in conf's folder. Error ID : " << xmlboss.ErrorID() << endl;
		exit(EXIT_FAILURE);
	}
}

void ConfigXml::loadingConfiguration() {
	loadingConfigurationLevel();
	loadingConfigurationTypeEnemy();
	loadingConfigurationBoss();
}