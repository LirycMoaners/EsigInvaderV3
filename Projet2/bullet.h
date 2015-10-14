#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SFML/Graphics.hpp>

class Bullet
{
	private:
		sf::CircleShape shape;
		int speed;

	public:
		Bullet();
		Bullet(sf::Vector2f, int);
		sf::CircleShape &getShape();
		void move();
		~Bullet();
};

#endif