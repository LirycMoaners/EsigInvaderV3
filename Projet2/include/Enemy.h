#pragma once
#include <SFML\Graphics.hpp>
#include "SpaceObject.h"
#include <iostream>
#include "Laser.h"

class Enemy : public SpaceObject
{
	protected:
		int dommage;
		int life;
		bool moveDown;
		sf::Vector2i anim;
		int speed = 10;
		int laserQty;
		int rate;
		int laserSpeed;
		int compteurEnemy;
		bool boss = false;

	public:
		//Enemy(float, float, sf::Texture&);
		Enemy(sf::Texture&, sf::Vector2f);
		Enemy(sf::Texture&, sf::Vector2f, int, int);
		int getDommage();
		void switchFps();
		vector<Laser*> shoot(sf::Texture&);
		void setLvl(int);
		void move();
		bool getType();
		~Enemy();
};

