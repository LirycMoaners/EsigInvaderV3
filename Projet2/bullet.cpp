#include <SFML/Graphics.hpp>
#include "bullet.h"

Bullet::Bullet() : speed(0)
{
	shape.setFillColor(sf::Color(250, 100, 50));
	shape.setRadius(10);
	shape.setPosition(0, 0);
}

Bullet::Bullet(sf::Vector2f pos, int spd) : speed(spd)
{
	shape.setFillColor(sf::Color(250, 100, 50));
	shape.setRadius(10);
	shape.setPosition(pos);
}

sf::CircleShape &Bullet::getShape()
{
	return shape;
}

void Bullet::move()
{
	shape.move(speed, 0);
}

Bullet::~Bullet()
{
	shape.~CircleShape();
}
