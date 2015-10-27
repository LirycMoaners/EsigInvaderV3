#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
class Bullet
{
	protected:
		sf::Sprite sprite;
		int anim;
		int speed;
		bool enemyBullet = false;

	public:
		Bullet();
		//Bullet(sf::Texture&, sf::Vector2f, int, bool enemy);
		Bullet(sf::Texture&, sf::Vector2f, int);
		Bullet(const Bullet&);
		sf::Sprite &getSprite();
		void move();
		bool isEnemyBullet();
		void switchFps();
		~Bullet();
};
