#pragma once
#include "Global.h"

// Définit le type de l'ennemi en fonction du niveau
class TypeEnemy
{
public:
	//TypeEnemy(int life, int	dommage,int speedFire, int speed)
	TypeEnemy(int life, int	dommage,int speedFire, int speed);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getSpeedFire();

private : 
	//la vitesse de déplacement de l'ennemi
	int speed;
	//la vie de l'ennemi
	int life;
	//Niveau de dégât
	int dommage;
	//la fréquence de tire de l'ennemi
	int speedFire;

};

