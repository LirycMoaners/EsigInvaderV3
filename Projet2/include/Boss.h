#pragma once
#include "Enemy.h"
#include "Global.h"
class Boss : public Enemy
{
	public:
		Boss(int life, int dommage, sf::Texture&);
		~Boss();
		void move();
};

