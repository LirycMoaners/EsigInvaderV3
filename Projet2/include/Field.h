#pragma once
#ifndef Field_H_INCLUDED
#define Field_H_INCLUDED

#include <iostream>
#include "../include/Bullet.h"
#include "../include/Spaceship.h"

using namespace std;

class Field
{
	private:
		vector<Bullet> bullets;
		Spaceship spaceship;

	public:
		Field();
		Spaceship &getSpaceship();
		vector<Bullet> &getBullets();
		void addBullet(Bullet);
		void collision(sf::RenderWindow&);
		~Field();
};

#endif