#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
class Bonus
{
	private:
		sf::Sprite sprite;
		int speed;
		int effect;
		int anim;

	public:
		Bonus(sf::Texture&, sf::Vector2f);
		int getEffect();
		sf::Sprite &getSprite();
		void move();
		void switchFps();
		~Bonus();
};

