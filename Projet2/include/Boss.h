#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
	public:
		Boss(int life, int dommage,int LaserSpeed, int speed, int rate, sf::Texture&, sf::Vector2f);
		//Boss(const Boss &);
		~Boss();
		void move();
		void move(sf::Sprite & sprite);
		void setPosition(float,float);
		vector<Laser*> shoot(sf::Texture &texture);
};

