#pragma once
#include "Global.h"

// D�finit le type de l'�n�mies en fonction du niveau
class TypeEnemy
{
public:
	TypeEnemy(int life, int	dommage,int speedFire);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getSpeedFire();

private : 
	//la vie de l'�n�mie
	int life;
	int dommage;
	int speedFire;

};

