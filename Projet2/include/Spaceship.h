#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include "../include/Weapon.h"

class Spaceship
{
	private:
		sf::CircleShape shape;
		Weapon weapon;

	public:
		Spaceship();
		sf::CircleShape &getShape();
		Weapon getWeapon();
		void move(int);
		~Spaceship();
};

#endif