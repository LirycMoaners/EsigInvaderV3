#include "..\include\TypeEnemy.h"



TypeEnemy::TypeEnemy(int life, int	dommage, int sizeEscouade)
{
	this->life = life;
	this->dommage = dommage;
	this->sizeEscouade = sizeEscouade;
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
int TypeEnemy::getSizeEscouade() {
	return this->sizeEscouade;
}