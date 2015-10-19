#include "..\include\Level.h"

Level::Level(int nb, int speed, TypeEnemy *type, Boss * boss, string url)
{
	this->nbEnemy = nb;
	this->speedEnemyFire = speed;
	this->type = type;
	this->boss = boss;
	this->urlImage = url;
}

int Level::getNbEnemy() {
	return this->nbEnemy;
}
TypeEnemy* Level::getEnemyType() {
	return this->type;
}
int Level::getSpeedEnemyFire() {
	return this->speedEnemyFire;
}
Boss *  Level::setBoss() {
	return this->boss;
}
string Level::getUrlImage() {
	return urlImage;
}

Level::~Level()
{
}
