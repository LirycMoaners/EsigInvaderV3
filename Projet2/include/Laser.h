#pragma once

#include "Bullet.h"

class Laser : public Bullet
{
	public:
		Laser();
		Laser(sf::Texture&, sf::Vector2f, int, int);
		void switchFps();
		~Laser();
};

