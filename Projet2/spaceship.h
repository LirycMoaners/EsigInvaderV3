#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include "weapon.h"

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