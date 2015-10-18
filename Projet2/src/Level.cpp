#include "..\include\Level.h"

Level::Level(int nb, int speed, string url) {
	this->nbEnemy = nb;
	this->speedEnemyFire = speed;
	this->urlImage = url;
	this->boss = Boss();
}

Level::Level(int nb, int health, int speed, int dommage, Boss boss, string url)
{
	this->nbEnemy = nb;
	this->healthEnemy = health;
	this->speedEnemyFire = speed;
	this->dommageEnemy = dommage;
	this->boss = boss;
	this->urlImage = url;
}

void Level::setNbEnemy(int nb) {
	this->nbEnemy = nb;
}
void Level::setHealthEnemy(int health) {
	this->healthEnemy = health;
}
void Level::setSpeedEnemyFire(int speedFire) {
	this->speedEnemyFire = speedFire;
}
void Level::setDommageEnemy(int dommage) {
	this->dommageEnemy = dommage;
}
void Level::setBoss(Boss b) {
	this->boss = b;
}
void Level::setUrlImage(string url) {
	this->urlImage = url;
}

int Level::getNbEnemy() {
	return this->nbEnemy;
}
int Level::getHealthEnemy() {
	return this->healthEnemy;
}
int Level::getSpeedEnemyFire() {
	return this->speedEnemyFire;
}
int Level::getDommageEnemy() {
	return this->dommageEnemy;
}
Boss & Level::setBoss() {
	return this->boss;
}
string Level::getUrlImage() {
	return urlImage;
}

Level::~Level()
{
}
