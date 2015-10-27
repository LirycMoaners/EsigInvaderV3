#pragma once
#include<string>
#include "Boss.h"
#include "TypeEnemy.h"

using namespace std;
class Level
{
	public:
		Level(int nb, int speed, TypeEnemy * type, Boss * boss,string url, string urlBoss);
		int getNbEnemy();
		int getSpeedEnemyFire();
		TypeEnemy* getEnemyType();
		Boss * getBoss();
		string getUrlImage();
		string getUrlImageBoss();
		~Level();
	private : 
		int nbEnemy;
		int healthEnemy;
		int speedEnemyFire;
		int dommageEnemy;
		Boss * boss;
		string urlImage;
		string urlBoss;
		TypeEnemy * type;
};

