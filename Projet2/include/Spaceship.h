#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include "../include/Weapon.h"
#include "../include/SpaceObject.h"

class Spaceship: public SpaceObject
{
	private:
		sf::Sprite sprite;
		sf::Vector2i anim;
		Weapon weapon;

	public:
		Spaceship(sf::Texture&);
		sf::Sprite &getSprite();
		Weapon &getWeapon();
		void move(int);
		void switchFps();
		~Spaceship();
};

#endif