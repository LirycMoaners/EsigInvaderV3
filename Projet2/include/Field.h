#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "../include/Bullet.h"
#include "../include/Spaceship.h"
#include "../include/Control.h"
#include "../include/Img.h"

using namespace std;

class Field
{
	private:
		Img img;
		vector<Bullet> bullets;
		Spaceship spaceship;
		Control c;

	public:
		Field();
		Spaceship &getSpaceship();
		vector<Bullet> &getBullets();
		void addBullets(vector<Bullet>&);
		void control();
		void collision(sf::RenderWindow&);
		~Field();
};

#endif