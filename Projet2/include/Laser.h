#pragma once

#include "Bullet.h"

class Laser : public Bullet
{
	public:
		//Laser()
		Laser();
		//Laser(sf::Texture&, int, int,sf::Sprite, int, int)
		Laser(sf::Texture&, int, int,sf::Sprite, int, int);
		//Selectionne les images par rapport au movement
		void switchFps();
		~Laser();
};

