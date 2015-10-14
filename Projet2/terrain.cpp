#include "terrain.h"

Terrain::Terrain() : spaceship(Spaceship()), bullets(NULL), c(Control()) {}

Spaceship &Terrain::getSpaceship()
{
	return spaceship;
}

vector<Bullet> &Terrain::getBullets()
{
	return bullets;
}

void Terrain::addBullets(vector<Bullet> b)
{
	for (int i = 0; i < b.size(); i++)
		bullets.push_back(b[i]);
}

void Terrain::control()
{
	c.arrow(spaceship);
	addBullets(c.space(spaceship));
}

void Terrain::collision(sf::RenderWindow &window)
{
	for (int i = 0; i < bullets.size(); i++)
		if (bullets[i].getShape().getPosition().x > window.getSize().x)
			bullets.erase(bullets.begin() + i);
}

Terrain::~Terrain()
{
	bullets.~vector();
	spaceship.~Spaceship();
}