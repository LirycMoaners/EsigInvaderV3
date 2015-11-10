#pragma once
#include "Global.h"

// Définit le type de l'ennemi en fonction du niveau
class TypeEnemy
{
public:
	//TypeEnemy(int life, int	dommage,int speedFire, int speed, int rate)
	TypeEnemy(int life, int	dommage,int speedFire, int speed, int rate, int laserQty, int score);
	~TypeEnemy();

	int getLife();
	int getDommage();
	int getLaserSpeed();
	int getSpeed();
	int getRate();
	int getLaserQty();
	int getScore();
private : 
	//la vitesse de déplacement de l'ennemi
	int speed;
	//la vie de l'ennemi
	int life;
	//Niveau de dégât
	int dommage;
	//Vitesse de déplacement des lasers
	int LaserSpeed;
	//Fréquence de sortie des lasers
	int rate;
	// Nombre de laser
	int laserQty;
	// Score par enemy
	int score;
};

