#pragma once

#include "Bullet.h"

class Rocket : public Bullet
{
	public:
		//Rocket()
		Rocket();
		Rocket(sf::Texture&,int,int, sf::Sprite, int, int);
		void switchFps();
		~Rocket();
};

