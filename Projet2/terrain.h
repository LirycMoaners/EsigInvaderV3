#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "bullet.h"
#include "spaceship.h"
#include "control.h"

using namespace std;

class Terrain
{
	private:
		vector<Bullet> bullets;
		Spaceship spaceship;
		Control c;

	public:
		Terrain();
		Spaceship &getSpaceship();
		vector<Bullet> &getBullets();
		void addBullets(vector<Bullet>);
		void control();
		void collision(sf::RenderWindow&);
		~Terrain();
};

#endif