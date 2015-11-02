#pragma once

#include "Bullet.h"

class Rocket : public Bullet
{
	public:
		Rocket();
		Rocket(sf::Texture&, sf::Vector2f, int, int);
		void switchFps();
		~Rocket();
};

