#pragma once

#include "Bullet.h"

class Laser : public Bullet
{
	public:
		//Laser()
		Laser();
		//Laser(sf::Texture&, sf::Vector2f, int, int)
		Laser(sf::Texture&, sf::Vector2f, int, int);
		// selectionne les images par rapport au movement
		void switchFps();
		~Laser();
};

