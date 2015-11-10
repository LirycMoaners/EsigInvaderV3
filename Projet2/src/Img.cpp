#include "..\include\Img.h"

Img::Img()
{
	background_t.loadFromFile("ressources/background.jpg");
	spaceship_t.loadFromFile("ressources/spaceship.png");
	rocket_t.loadFromFile("ressources/rocket.png");
	enemy_t.loadFromFile("ressources/enemy.png");
	laser_t.loadFromFile("ressources/laser.png");
	boss_t.loadFromFile("ressources/Boss.png");
	home_t.loadFromFile("ressources/home.png");
	button_t.loadFromFile("ressources/button.png");
	explosion_t.loadFromFile("ressources/explosion.png");
	bonus_t.loadFromFile("ressources/bonus_malus.png");
}

sf::Texture &Img::getSpaceship_t()
{
	return spaceship_t;
}
sf::Texture &Img::getRocket_t()
{
	return rocket_t;
}
sf::Texture &Img::getLaser_t()
{
	return laser_t;
}
sf::Texture &Img::getBackground_t()
{
	return background_t;
}
sf::Texture &Img::getExplosion_t()
{
	return explosion_t;
}
sf::Texture &Img::getEnemy_t() 
{
	return enemy_t;
}

sf::Texture &Img::getBoss_t()
{
	return boss_t;
}

sf::Texture &Img::getHome_t()
{
	return home_t;
}

sf::Texture &Img::getButton_t()
{
	return button_t;
}

sf::Texture &Img::getBonus_t()
{
	return bonus_t;
}

void Img::setBoss_t(string name) {
	boss_t.loadFromFile(name.c_str());
}
void Img::setEnemy_t(string name) {
	enemy_t.loadFromFile(name.c_str());
}
void Img::setSpaceship_t(string name) {
	spaceship_t.loadFromFile(name.c_str());
}

Img::~Img() {}