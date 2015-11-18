#include "..\include\ConfigXml.h"

ConfigXml::ConfigXml()
{
	//Param�trage par d�faut
	setting = new Settings(0, true, true, true, 50, 100, false);
	loadingConfigurationOptions();


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
Settings* ConfigXml::getSettings() {
	return setting;
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
	delete setting;
}

void ConfigXml::loadingConfigurationLevel() {
	cout << "Loading Level Configuration" << endl;
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
	cout << "End Loading Level Configuration" << endl;
}
void ConfigXml::loadingConfigurationTypeEnemy() {
	cout << "Loading Enemy Configuration " << endl;
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
					typeList.push_back(new TypeEnemy(life, dommage, speedEnemyFire, speed, rate, laserQty, score));
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

	cout << "End Loading Enemy Configuration " << endl;
}
void ConfigXml::loadingConfigurationBoss() {
	cout << "Loading Boss Configuration " << endl;
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
				int life = -1, dommage = -1, speedEnemyFire = -1, speed = -1, rate = -1, laserQty = -1, score = -1;
				// R�cup�ration de tout les champs disponible
				if (levelBoss->FirstChildElement("Life") != NULL)
					life = stoi(levelBoss->FirstChildElement("Life")->GetText());
				if (levelBoss->FirstChildElement("Dommage") != NULL)
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
		std::cerr << "Failed to open the file confboss.xml in conf's folder. Error ID : " << xmlboss.ErrorID() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "End Loading Boss Configuration " << endl;
}

void ConfigXml::loadingConfigurationOptions() {
	cout << "Loading Options Configuration " << endl;
	tinyxml2::XMLDocument xmloption;
	xmloption.LoadFile("conf/options.xml");
	if (xmloption.ErrorID() == 0) {
		try {
			tinyxml2::XMLElement * root = xmloption.RootElement();
			tinyxml2::XMLElement * elemt = root->FirstChildElement("resolution");
			int reso = stoi(elemt->GetText());
			elemt = root->FirstChildElement("SoundBackground");
			bool soundBack = stoi(elemt->GetText());
			elemt = root->FirstChildElement("SoundPlayer");
			bool soundPlayer = stoi(elemt->GetText());
			elemt = root->FirstChildElement("SoundEnemy");
			bool soundEnemy = stoi(elemt->GetText());
			elemt = root->FirstChildElement("VolumeMusic");
			int volumeMusic = stoi(elemt->GetText());
			elemt = root->FirstChildElement("VolumeSound");
			int volumeSound = stoi(elemt->GetText());
			elemt = root->FirstChildElement("fullScreen");
			bool fullscreen = stoi(elemt->GetText());
			this->setting->changeSettings(reso, soundEnemy, soundPlayer, soundBack, volumeMusic, volumeSound, fullscreen);
		}
		catch (const std::invalid_argument& ia) {
			std::cerr << "Invalid argument: " << ia.what() << '\n';
		}
	}
	else {
		std::cout << "Error searching configuration" << std::endl;
		std::cerr << "Failed to open the file options.xml in conf's folder. Error ID : " << xmloption.ErrorID() << endl;
	}
	cout << "End Loading Options Configuration " << endl;
}

void ConfigXml::setSetting(Settings * s) {
	tinyxml2::XMLDocument xmloption;
	tinyxml2::XMLError error = xmloption.LoadFile("conf/options.xml");
	if (error == tinyxml2::XML_SUCCESS) {
		tinyxml2::XMLElement * root = xmloption.RootElement();
		tinyxml2::XMLElement * elemt = root->FirstChildElement("resolution");
		elemt->SetText(s->getResolutionInt());
		elemt = root->FirstChildElement("SoundBackground");
		elemt->SetText(s->getSoundBackground() ? 1 : 0);
		elemt = root->FirstChildElement("SoundPlayer");
		elemt->SetText(s->getSoundPlayer() ? 1 : 0);
		elemt = root->FirstChildElement("SoundEnemy");
		elemt->SetText(s->getSoundEnemy() ? 1 : 0);
		elemt = root->FirstChildElement("VolumeMusic");
		elemt->SetText(s->getVolumeMusic());
		elemt = root->FirstChildElement("VolumeSound");
		elemt->SetText(s->getVolumeSound());
		elemt = root->FirstChildElement("fullScreen");
		elemt->SetText(s->isFullscreen() ? 1 : 0);
	}
	else
	{
		//Create the setting file
		tinyxml2::XMLNode * root = xmloption.NewElement("settings");
		xmloption.InsertFirstChild(root);
		tinyxml2::XMLElement * resoElemt = xmloption.NewElement("resolution");
		resoElemt->SetText(s->getResolutionInt());
		root->InsertFirstChild(resoElemt);
		tinyxml2::XMLElement * sndBgElemt = xmloption.NewElement("SoundBackground");
		sndBgElemt->SetText(s->getSoundBackground() ? 1 : 0);
		root->InsertFirstChild(sndBgElemt);
		tinyxml2::XMLElement * sndPlayerElemt = xmloption.NewElement("SoundPlayer");
		sndPlayerElemt->SetText(s->getSoundPlayer() ? 1 : 0);
		root->InsertFirstChild(sndPlayerElemt);
		tinyxml2::XMLElement * sndEnemyElemt = xmloption.NewElement("SoundEnemy");
		sndEnemyElemt->SetText(s->getSoundEnemy() ? 1 : 0);
		root->InsertFirstChild(sndEnemyElemt);
		tinyxml2::XMLElement * sndVolumeElemt = xmloption.NewElement("VolumeSound");
		sndVolumeElemt->SetText(s->getVolumeSound());
		root->InsertFirstChild(sndVolumeElemt);
		tinyxml2::XMLElement * musicVolumeElemt = xmloption.NewElement("VolumeMusic");
		musicVolumeElemt->SetText(s->getVolumeMusic());
		root->InsertFirstChild(musicVolumeElemt);
		tinyxml2::XMLElement * fullscreenElemt = xmloption.NewElement("fullScreen");
		fullscreenElemt->SetText(s->isFullscreen() ? 1 : 0);
		root->InsertFirstChild(fullscreenElemt);
	}

	//Save the changments into XML File
	tinyxml2::XMLError wrError = xmloption.SaveFile("conf/options.xml");
	if (wrError != NULL)
	{
		std::cout << "Impossible to save the setting" << std::endl;
		std::cerr << "Fail to open the file options.xml in the conf's folder Error ID : " << xmloption.ErrorID() << std::endl;
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
	else {
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