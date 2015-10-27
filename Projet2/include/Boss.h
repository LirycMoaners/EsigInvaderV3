#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
	public:
		Boss(int life, int dommage, int speed, sf::Texture&, sf::Vector2f);
		~Boss();
		void move();
		void setPosition(float,float);
};

