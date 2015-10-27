#include "..\include\TypeEnemy.h"



TypeEnemy::TypeEnemy(int life, int	dommage, int speedFire)
{
	this->life = life;
	this->dommage = dommage;
	this->speedFire = speedFire;
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