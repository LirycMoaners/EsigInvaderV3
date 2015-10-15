#include "Img.h"

Img::Img()
{
	spaceship_t.loadFromFile("ressources/spaceship.png");
	bullet_t.loadFromFile("ressources/bullet.png");
}

sf::Texture &Img::getSpaceship_t()
{
	return spaceship_t;
}
sf::Texture &Img::getBullet_t()
{
	return bullet_t;
}