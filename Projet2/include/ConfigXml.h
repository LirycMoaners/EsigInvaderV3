#pragma once
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>
#include "Level.h"
#include "Settings.h"
using namespace std;

class ConfigXml
{
	public:
		ConfigXml();
		void loadingConfiguration();
		void CreateScore(int score, std::string name,std::string mode);
		//void setSetting(Settings *s);
		~ConfigXml();

		std::vector<Level*> getLevelList();
		std::vector<TypeEnemy*> getTypeEnemyList();
		std::vector<TypeEnemy*> getBossList();
		Settings* getSettings();
		void setSetting(Settings * s);

	private : 
		void loadingConfigurationLevel();
		void loadingConfigurationTypeEnemy();
		void loadingConfigurationBoss();
		void loadingConfigurationOptions();

		Settings * setting;
		std::vector<Level*> levelList;
		std::vector<TypeEnemy*> typeList;
		std::vector<TypeEnemy*> bossList;
};

