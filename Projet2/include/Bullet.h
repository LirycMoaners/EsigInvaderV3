#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet
{
	private:
		sf::Sprite sprite;
		int anim;
		int speed;

	public:
		Bullet();
		Bullet(sf::Texture&, sf::Vector2f, int);
		Bullet(const Bullet&);
		sf::Sprite &getSprite();
		void move();
		void switchFps();
		~Bullet();
};

#endif