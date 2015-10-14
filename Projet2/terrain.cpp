#include "terrain.h"

Terrain::Terrain() : spaceship(Spaceship()), bullets(NULL) {}

Spaceship &Terrain::getSpaceship()
{
	return spaceship;
}

vector<Bullet> &Terrain::getBullets()
{
	return bullets;
}

void Terrain::addBullet(Bullet b)
{
	bullets.push_back(b);
}

void Terrain::collision(sf::RenderWindow &window)
{
	for (int i = 0; i < bullets.size(); i++)
		if (bullets[i].getShape().getPosition().x + 100 > window.getSize().x)
			bullets.erase(bullets.begin() + i);
}

Terrain::~Terrain()
{
	bullets.~vector();
	spaceship.~Spaceship();
}