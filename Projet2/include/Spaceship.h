#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include "../include/Weapon.h"

class Spaceship
{
	private:
		sf::Sprite sprite;
		sf::Vector2i anim;
		Weapon weapon;

	public:
		Spaceship();
		Spaceship(sf::Texture&);
		sf::Sprite &getSprite();
		Weapon &getWeapon();
		void move(int);
		void move(int previous_x, int previous_y);
		void switchFps();
		~Spaceship();
};

#endif