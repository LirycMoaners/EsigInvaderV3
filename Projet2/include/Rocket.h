#pragma once

#include "Bullet.h"

class Rocket : public Bullet
{
	public:
		//Rocket()
		Rocket();
		//Rocket(sf::Texture&, sf::Vector2f, int, int)
		Rocket(sf::Texture&, sf::Vector2f, int, int);
		// selectionne les images par rapport au movement
		void switchFps();
		~Rocket();
};

