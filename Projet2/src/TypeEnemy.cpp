#include "..\include\TypeEnemy.h"



TypeEnemy::TypeEnemy(int life, int	dommage, int LaserSpeed, int speed, int rate, int laserQty, int score)
{
	this->life = life;
	this->dommage = dommage;
	this->LaserSpeed = LaserSpeed;
	this->speed = speed;
	this->rate = rate;
	this->laserQty = laserQty;
	this->score = score;
}
int TypeEnemy::getScore() {
	return score;
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
int TypeEnemy::getLaserQty() {
	return this->laserQty;
}