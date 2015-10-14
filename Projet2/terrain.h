#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "bullet.h"
#include "spaceship.h"

using namespace std;

class Terrain
{
	private:
		vector<Bullet> bullets;
		Spaceship spaceship;

	public:
		Terrain();
		Spaceship &getSpaceship();
		vector<Bullet> &getBullets();
		void addBullet(Bullet);
		void collision(sf::RenderWindow&);
		~Terrain();
};

#endif