#include "../include/Field.h"

Field::Field() : spaceship(Spaceship()), bullets(NULL) {}

Spaceship &Field::getSpaceship()
{
	return spaceship;
}

vector<Bullet> &Field::getBullets()
{
	return bullets;
}

void Field::addBullet(Bullet b)
{
	bullets.push_back(b);
}

void Field::collision(sf::RenderWindow &window)
{
	for (int i = 0; i < bullets.size(); i++)
		if (bullets[i].getShape().getPosition().x > window.getSize().x)
			bullets.erase(bullets.begin() + i);
}

Field::~Field()
{
	bullets.~vector();
	spaceship.~Spaceship();
}