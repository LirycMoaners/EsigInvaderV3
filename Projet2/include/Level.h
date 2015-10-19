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

		int getNbEnemy();
		int getSpeedEnemyFire();
		TypeEnemy* getEnemyType();
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

