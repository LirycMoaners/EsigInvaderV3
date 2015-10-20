#pragma once
#include <SFML\Graphics.hpp>
#include "SpaceObject.h"
#include "Weapon.h"
#include<iostream>
#include "Global.h"

class Enemy : public SpaceObject
{
	protected:
		int dommage;
		bool moveDown;
		Weapon weapon;
		bool boss = false;

	public:
		Enemy(float, float, sf::Texture&);
		int getDommage();
		Weapon &getWeapon();
		void move();
		bool getType();
		~Enemy();
};

