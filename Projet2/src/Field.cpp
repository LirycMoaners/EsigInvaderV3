#include "../include/Field.h"

Field::Field() : spaceship(Spaceship()), bullets(NULL), c(Control()) {}

Spaceship &Field::getSpaceship()
{
	return spaceship;
}

vector<Bullet> &Field::getBullets()
{
	return bullets;
}

void Field::addBullets(vector<Bullet> b)
{
	for (int i = 0; i < b.size(); i++)
		bullets.push_back(b[i]);
}

void Field::control()
{
	c.arrow(spaceship);
	addBullets(c.space(spaceship));
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