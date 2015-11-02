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

