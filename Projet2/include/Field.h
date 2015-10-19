#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "Bullet.h"
#include "Spaceship.h"
#include "Keyboard.h"
#include "Armband.h"
#include "Img.h"
#include "Enemy.h"

using namespace std;

class Field
{
	private:
		Img img;
		sf::Clock timer;
		sf::Sprite background;
<<<<<<< HEAD
		vector<Bullet*> bullets;
		Spaceship* spaceship;
=======
		Spaceship spaceship;
>>>>>>> ecf890acfa31a8ae2623c310c6fdb7375f76b235
		Control *c;
		vector<Bullet*> bullets;
		vector<Enemy*> enemies;

	public:
		Field(bool available);
		//Field();
		Spaceship *getSpaceship();
		vector<Bullet*> &getBullets();
		vector<Enemy*> &getEnemies();
		void addBullets(vector<Bullet*>&);
		void control();
		void addEnemies();
		void collision(sf::RenderWindow*);
		void enemyCollideSpaceShip();
		void bulletCollideEnemy();
		void removeBullet(int i);
		~Field();
};

#endif