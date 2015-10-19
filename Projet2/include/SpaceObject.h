#pragma once
#include "SFML/Graphics.hpp"

class SpaceObject
{
	protected:
		sf::Sprite sprite;
		unsigned int health;
		int speed;

	public:
		SpaceObject(sf::Texture &t,int,int);
		~SpaceObject();

		sf::Sprite &getSprite();
		virtual void move(int) = 0;

		int getHealth();
		int getSpeed();
};

