#pragma once
#include <SFML\Graphics.hpp>
#include "SpaceObject.h"
#include "Weapon.h"
#include<iostream>

class Enemy : public SpaceObject
{
	protected:
		int dommage;
		bool moveDown;
		Weapon weapon;

	public:
		Enemy(float, float, sf::Texture&);
		int getDommage();
		Weapon &getWeapon();
		void move();

		~Enemy();
};

