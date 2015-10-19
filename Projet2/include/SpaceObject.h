#pragma once
#include "SFML/Graphics.hpp"
#include "Global.h"

class SpaceObject
{
	protected:
		sf::Sprite sprite;
		int health;
		int speed;

	public:
		SpaceObject(sf::Texture &t,int,int);
		~SpaceObject();

		sf::Sprite &getSprite();
		virtual void move() {};

		int getHealth();
		int getSpeed();
		void takeDommage(int dommage);
		bool isAlive();
};

