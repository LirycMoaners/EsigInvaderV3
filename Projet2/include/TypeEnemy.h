#pragma once
#include "Global.h"
class TypeEnemy
{
public:
	TypeEnemy(int life, int	dommage,int speedFire, int speed);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getSpeedFire();

private : 
	int speed;
	int life;
	int dommage;
	int speedFire;

};

