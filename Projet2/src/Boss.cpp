#include "..\include\Boss.h"

Boss::Boss() {

}

Boss::Boss(int life, int dommage)
{
	this->health = life;
	this->dommage = dommage;
}


Boss::~Boss()
{
}
