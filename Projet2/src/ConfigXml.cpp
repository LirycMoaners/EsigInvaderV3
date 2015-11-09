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
			try {
				int life = -1, dommage = -1, speedEnemyFire = -1, speed = -1, rate = -1, laserQty = -1, score = -1;
				// Récupération de tout les champs disponible
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
					// Ajout d'un nouveau boss à la liste 
					typeList.push_back(new TypeEnemy(life, dommage, speedEnemyFire, speed , rate, laserQty, score));
					// Passage à la balise suivante
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
		// Positionnement de l'element à la première balise Boss disponible;
		tinyxml2::XMLElement * levelBoss = nodeEnemy->FirstChildElement("Bosses")->FirstChildElement("Boss");
		while (levelBoss) {
			try {
				int life = -1, dommage = -1, speedEnemyFire = -1, speed = -1, rate = -1, laserQty =-1, score = -1;
				// Récupération de tout les champs disponible
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
					// Ajout d'un nouveau boss à la liste 
					bossList.push_back(new TypeEnemy(life, dommage, speedEnemyFire, speed, rate, laserQty, score));
					// Passage à la balise suivante
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

void ConfigXml::CreateScore(int score, string name, string mode) {
	tinyxml2::XMLDocument xmlScore;
	tinyxml2::XMLError error = xmlScore.LoadFile("conf/data.db");
	
	if (name == "") {
		name = "UNKNOWN";
	}

	if (error == tinyxml2::XMLError::XML_SUCCESS) {
		tinyxml2::XMLNode * root = xmlScore.RootElement();
		//tinyxml2::XMLElement * node = root->FirstChildElement("Scores");

		tinyxml2::XMLElement * temps = xmlScore.NewElement("Score");
		
		temps->SetAttribute("user", name.c_str());
		temps->SetAttribute("value", score);
		temps->SetAttribute("mode", mode.c_str());
		
		//Find the first score smaller than the current score
		tinyxml2::XMLElement* testedScoreNode = root->FirstChildElement("Score");
		int value = 0;
		do
		{
			//Find score values
			try
			{
				value = atoi(testedScoreNode->Attribute("value"));
			}
			catch (...) { std::cout << "Error in the XML score file!" << std::endl; break; }

			//Take the next score if the tested score is higher than the current player score
			if (value < score)
				break;
			else
				testedScoreNode = testedScoreNode->NextSiblingElement("Score");

		} while (testedScoreNode);

		if (testedScoreNode == root->FirstChildElement("Score"))
			root->InsertFirstChild(temps);
		else if (testedScoreNode)
			root->InsertAfterChild(testedScoreNode, temps);
		else
			root->InsertEndChild(temps);
		xmlScore.SaveFile("conf/data.db");
	}
	else  {
		if (error == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND) {
			tinyxml2::XMLElement * result = xmlScore.NewElement("Scores");
			tinyxml2::XMLElement * temps = xmlScore.NewElement("Score");
			temps->SetAttribute("user", name.c_str());
			temps->SetAttribute("value", score);
			temps->SetAttribute("mode", mode.c_str());
			result->InsertEndChild(temps);

			xmlScore.InsertEndChild(result);
			xmlScore.SaveFile("conf/data.db");
		}

	}
}

void ConfigXml::loadingConfiguration() {
	loadingConfigurationLevel();
	loadingConfigurationTypeEnemy();
	loadingConfigurationBoss();
}