#pragma once
#include "Global.h"

// Définit le type de l'énémies en fonction du niveau
class TypeEnemy
{
public:
	TypeEnemy(int life, int	dommage,int speedFire, int speed, int rate);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getLaserSpeed();
	int getSpeed();
	int getRate();
private : 
	int speed;
	//la vie de l'énémie
	int life;
	int dommage;
	int LaserSpeed;
	int rate;
};

