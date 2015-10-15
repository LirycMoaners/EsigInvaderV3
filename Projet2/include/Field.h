#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "Bullet.h"
#include "Spaceship.h"
#include "Keyboard.h"
#include "Armband.h"
#include "Img.h"

using namespace std;

class Field
{
	private:
		Img img;
		vector<Bullet> bullets;
		Spaceship spaceship;
		Control *c;

	public:
		Field(bool available);
		Spaceship &getSpaceship();
		vector<Bullet> &getBullets();
		void addBullets(vector<Bullet>&);
		void control();
		void collision(sf::RenderWindow&);
		~Field();
};

#endif