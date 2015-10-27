#pragma once

#include "Weapon.h"
#include "SpaceObject.h"

class Spaceship: public SpaceObject
{
	private:
		sf::Sprite sprite;
		sf::Vector2i anim;
		Weapon weapon;

	public:
		Spaceship(sf::Texture&);
		Spaceship();
		sf::Sprite &getSprite();
		Weapon &getWeapon();
		void move(int);
		void switchFps();
		~Spaceship();
};
