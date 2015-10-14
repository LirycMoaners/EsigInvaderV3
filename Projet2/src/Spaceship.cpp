#include "../include/spaceship.h"

Spaceship::Spaceship() : weapon(Weapon(1))
{
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setRadius(50);
	shape.setPosition(100, 100);
}

sf::CircleShape &Spaceship::getShape()
{
	return shape;
}

Weapon Spaceship::getWeapon()
{
	return weapon;
}

void Spaceship::move(int dir)
{
	switch (dir)
	{
		case 1:
			shape.move(0, -5);
			break;
		case 2:
			shape.move(0, 5);
			break;
		case 3:
			shape.move(-5, 0);
			break;
		case 4:
			shape.move(5, 0);
			break;
	}
}

Spaceship::~Spaceship()
{
	shape.~CircleShape();
	weapon.~Weapon();
}