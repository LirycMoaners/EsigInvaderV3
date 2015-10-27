#pragma once
#include "Global.h"
class TypeEnemy
{
public:
	TypeEnemy(int life, int	dommage,int speedFire);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getSpeedFire();

private : 
	int life;
	int dommage;
	int speedFire;

};

