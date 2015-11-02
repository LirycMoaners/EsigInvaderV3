#pragma once
#include "Global.h"

// Définit le type de l'énémies en fonction du niveau
class TypeEnemy
{
public:
	TypeEnemy(int life, int	dommage,int speedFire);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getSpeedFire();

private : 
	//la vie de l'énémie
	int life;
	int dommage;
	int speedFire;

};

