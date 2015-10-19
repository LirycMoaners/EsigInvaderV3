#include "..\include\Boss.h"

Boss::Boss(int life, int dommage, sf::Texture& texture) : Enemy(5,5,texture)
{
	this->health = life;
	this->dommage = dommage;
}

void Boss::move(){}

Boss::~Boss()
{
	std::cout << "Call Destructor boss" << std::endl;
}
