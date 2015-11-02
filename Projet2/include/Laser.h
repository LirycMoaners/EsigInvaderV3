#pragma once

#include "Bullet.h"

class Laser : public Bullet
{
	public:
		//Laser()
		Laser();
		Laser(sf::Texture&, int, int,sf::Sprite, int, int);
		void switchFps();
		~Laser();
};

