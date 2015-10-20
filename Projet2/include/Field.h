#pragma once

#include <iostream>
#include "Bullet.h"
#include "Spaceship.h"
#include "Keyboard.h"
#include "Armband.h"
#include "Img.h"
#include "Enemy.h"
#include "Global.h"
#include "Level.h"
#include "Boss.h"

using namespace std;

class Field
{
	private:
		Img* img;
		sf::Clock timer;
		sf::Sprite background;
		Spaceship* spaceship;
		int compteurEnemies;
		Level* level;
		Control *c;
		vector<Bullet*> bullets;
		vector<Enemy*> enemies;
		bool BossPop = false;
	public:
		Field(bool available, Img* img,Level* l);
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