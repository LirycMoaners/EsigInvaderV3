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
		bool enemyBullet = false;

	public:
		Bullet();
		Bullet(sf::Texture&, sf::Vector2f, int, bool enemy);
		Bullet(const Bullet&);
		sf::Sprite &getSprite();
		void move();
		void switchFps();
		~Bullet();
};

#endif