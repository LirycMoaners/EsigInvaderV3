#include "Img.h"


Img::Img()
{
	spaceship_t.loadFromFile("ressources/spaceship.png");
	bullet_t.loadFromFile("ressources/bullet.png");
	background_t.loadFromFile("ressources/background.jpg");
	enemy_t.loadFromFile("ressources/enemy.png");
}

sf::Texture &Img::getSpaceship_t()
{
	return spaceship_t;
}
sf::Texture &Img::getBullet_t()
{
	return bullet_t;
}

sf::Texture &Img::getBackground_t()
{
	return background_t;
}
sf::Texture &Img::getEnemy_t() 
{
	return enemy_t;
}

sf::Texture &Img::getBoss_t()
{
	return boss_t;
}

void Img::setBoss_t(string name) {
	boss_t.loadFromFile(name.c_str());
}

Img::~Img() {}