#include "..\include\TypeEnemy.h"



TypeEnemy::TypeEnemy(int life, int	dommage, int speedFire, int speed)
{
	this->life = life;
	this->dommage = dommage;
	this->speedFire = speedFire;
	this->speed = speed;
}


TypeEnemy::~TypeEnemy()
{
}


int TypeEnemy::getLife() {
	return this->life;
}
int TypeEnemy::getDommage() {
	return this->dommage;
}
int TypeEnemy::getSpeedFire() {
	return this->speedFire;
}