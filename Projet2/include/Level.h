#pragma once
#include<string>
#include "Boss.h"
#include "TypeEnemy.h"
#include "Global.h"
using namespace std;
class Level
{
public:
	Level(int nb, int speed, TypeEnemy * type, Boss * boss,string url);
	Level(int, int, string);
	void setNbEnemy(int);
	void setHealthEnemy(int);
	void setSpeedEnemyFire(int);
	void setDommageEnemy(int);
	void setBoss(Boss *);
	void setUrlImage(string);

	int getNbEnemy();
	int getHealthEnemy();
	int getSpeedEnemyFire();
	int getDommageEnemy();
	Boss * setBoss();
	string getUrlImage();

	~Level();
private : 
	int nbEnemy;
	int healthEnemy;
	int speedEnemyFire;
	int dommageEnemy;
	Boss * boss;
	string urlImage;
	TypeEnemy * type;
};

