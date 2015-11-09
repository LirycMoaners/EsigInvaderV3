#pragma once
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>
#include "Level.h"
#include "TypeEnemy.h"
#include "Boss.h"
class ConfigXml
{
public:
	ConfigXml();
	void loadingConfiguration();
	void CreateScore(int score, string name,string mode);
	~ConfigXml();

	vector<Level*> getLevelList();
	vector<TypeEnemy*> getTypeEnemyList();
	vector<TypeEnemy*> getBossList();

private : 
	void loadingConfigurationLevel();
	void loadingConfigurationTypeEnemy();
	void loadingConfigurationBoss();

	vector<Level*> levelList;
	vector<TypeEnemy*> typeList;
	vector<TypeEnemy*> bossList;
};

