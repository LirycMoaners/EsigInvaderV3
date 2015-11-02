#include "..\include\TypeEnemy.h"



TypeEnemy::TypeEnemy(int life, int	dommage, int LaserSpeed, int speed, int rate)
{
	this->life = life;
	this->dommage = dommage;
	this->LaserSpeed = LaserSpeed;
	this->speed = speed;
	this->rate = rate;
}


TypeEnemy::~TypeEnemy()
{
}
int TypeEnemy::getSpeed() {
	return speed;
}
int TypeEnemy::getRate() {
	return rate;
}
int TypeEnemy::getLife() {
	return this->life;
}
int TypeEnemy::getDommage() {
	return this->dommage;
}
int TypeEnemy::getLaserSpeed() {
	return this->LaserSpeed;
}