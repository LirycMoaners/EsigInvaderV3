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
		// R�cup�ration de la premi�re balise Level
		tinyxml2::XMLElement * levelResult = node->FirstChildElement("Levels")->FirstChildElement("Level");
		while (levelResult != NULL) {
			int nbPattern;
			string background;
			// R�cup�ration du Nb de patern permettant le niveau
			nbPattern = stoi(levelResult->FirstChildElement("NbPatern")->GetText());
			background = levelResult->FirstChildElement("UrlImageBackground")->GetText();
			levelList.push_back(new Level(nbPattern, background));
			// Passage � la balise Level Suivante
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
		// R�cup�ration de la premi�re balise Enemy disponible;
		tinyxml2::XMLElement * levelEnemy = nodeEnemy->FirstChildElement("Enemies")->FirstChildElement("Enemy");
		while (levelEnemy) {
			try {
				int life = -1, dommage = -1, speedEnemyFire = -1, speed = -1, rate = -1, laserQty = -1, score = -1;
				// R�cup�ration de tout les champs disponible
				if (levelEnemy->FirstChildElement("Life") != NULL)
					life = stoi(levelEnemy->FirstChildElement("Life")->GetText());
				if (levelEnemy->FirstChildElement("Dommage") != NULL)
					dommage = stoi(levelEnemy->FirstChildElement("Dommage")->GetText());
				if (levelEnemy->FirstChildElement("LaserSpeed") != NULL)
					speedEnemyFire = stoi(levelEnemy->FirstChildElement("LaserSpeed")->GetText());
				if (levelEnemy->FirstChildElement("Speed") != NULL)
					speed = stoi(levelEnemy->FirstChildElement("Speed")->GetText());
				if (levelEnemy->FirstChildElement("Rate") != NULL)
					rate = stoi(levelEnemy->FirstChildElement("Rate")->GetText());
				if (levelEnemy->FirstChildElement("LaserQty") != NULL)
					laserQty = stoi(levelEnemy->FirstChildElement("LaserQty")->GetText());
				if (levelEnemy->FirstChildElement("Score") != NULL)
					score = stoi(levelEnemy->FirstChildElement("Score")->GetText());

				if (life != -1 && dommage != -1 && speedEnemyFire != -1 && speed != -1 && rate != -1 && laserQty != -1 && score != -1)
				{
					// Ajout d'un nouveau boss � la liste 
					typeList.push_back(new TypeEnemy(life, dommage, speedEnemyFire, speed , rate, laserQty, score));
					// Passage � la balise suivante
					levelEnemy = levelEnemy->NextSiblingElement("Enemy");
				}
				else {
					std::cout << "Wrong XML for the BOSS" << endl;
					exit(EXIT_FAILURE);
				}
			}
			catch (const std::invalid_argument& ia) {
				std::cerr << "Invalid argument: " << ia.what() << '\n';
			}
			
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
		// Positionnement de l'element � la premi�re balise Boss disponible;
		tinyxml2::XMLElement * levelBoss = nodeEnemy->FirstChildElement("Bosses")->FirstChildElement("Boss");
		while (levelBoss) {
			try {
				int life = -1, dommage = -1, speedEnemyFire = -1, speed = -1, rate = -1, laserQty =-1, score = -1;
				// R�cup�ration de tout les champs disponible
				if(levelBoss->FirstChildElement("Life") != NULL)
					life = stoi(levelBoss->FirstChildElement("Life")->GetText());
				if(levelBoss->FirstChildElement("Dommage") != NULL)
					dommage = stoi(levelBoss->FirstChildElement("Dommage")->GetText());
				if (levelBoss->FirstChildElement("LaserSpeed") != NULL)
					speedEnemyFire = stoi(levelBoss->FirstChildElement("LaserSpeed")->GetText());
				if (levelBoss->FirstChildElement("Speed") != NULL)
					speed = stoi(levelBoss->FirstChildElement("Speed")->GetText());
				if (levelBoss->FirstChildElement("Rate") != NULL)
					rate = stoi(levelBoss->FirstChildElement("Rate")->GetText());
				if (levelBoss->FirstChildElement("LaserQty") != NULL)
					laserQty = stoi(levelBoss->FirstChildElement("LaserQty")->GetText());
				if (levelBoss->FirstChildElement("Score") != NULL)
					score = stoi(levelBoss->FirstChildElement("Score")->GetText());

				if (life != -1 && dommage != -1 && speedEnemyFire != -1 && speed != -1 && rate != -1 && laserQty != -1 && score != -1)
				{
					// Ajout d'un nouveau boss � la liste 
					bossList.push_back(new TypeEnemy(life, dommage, speedEnemyFire, speed, rate, laserQty, score));
					// Passage � la balise suivante
					levelBoss = levelBoss->NextSiblingElement("Boss");
				}
				else {
					std::cout<<"Wrong XML for the BOSS" << endl;
					exit(EXIT_FAILURE);
				}
			}
			catch (const std::invalid_argument& ia) {
					std::cerr << "Invalid argument: " << ia.what() << '\n';
			}
			
		}
	}
	else {
		std::cout << "Error searching enemies" << std::endl;
		std::cerr << "Failed to open the file confboss.xml in conf's folder. Error ID : " << xmlboss.ErrorID() << endl;
		exit(EXIT_FAILURE);
	}
}

void ConfigXml::CreateScore(int score, string name) {
	tinyxml2::XMLDocument xmlScore;
	tinyxml2::XMLError error = xmlScore.LoadFile("data.db");
	
	if (error == tinyxml2::XMLError::XML_SUCCESS) {
		tinyxml2::XMLNode * root = xmlScore.RootElement();
		tinyxml2::XMLElement * node = root->FirstChildElement("Scores");

		tinyxml2::XMLElement * temps = xmlScore.NewElement("Score");
		temps->SetAttribute("name", name.c_str());
		temps->SetAttribute("score", score);
		root->InsertEndChild(temps);
		xmlScore.SaveFile("data.db");
	}
	else {
		if (error == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND) {
			tinyxml2::XMLElement * result = xmlScore.NewElement("Scores");
			tinyxml2::XMLElement * temps = xmlScore.NewElement("Score");
			temps->SetAttribute("name", name.c_str());
			temps->SetAttribute("score", score);
			result->InsertEndChild(temps);

			xmlScore.InsertEndChild(result);
			xmlScore.SaveFile("data.db");
		}
	}
}

void ConfigXml::loadingConfiguration() {
	loadingConfigurationLevel();
	loadingConfigurationTypeEnemy();
	loadingConfigurationBoss();
}