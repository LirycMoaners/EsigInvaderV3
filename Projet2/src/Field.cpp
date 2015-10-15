#include "../include/Field.h"

Field::Field() : bullets(NULL)
{
	img = Img();
	c = new Armband();
	if (!c->getStatus()) {
		delete c;
		c = new Keyboard();
	}
	spaceship = Spaceship(img.getSpaceship_t());
}

Spaceship &Field::getSpaceship()
{
	return spaceship;
}

vector<Bullet> &Field::getBullets()
{
	return bullets;
}

void Field::addBullets(vector<Bullet> &b)
{
	vector<Bullet> bullets = b;
	for (int i = 0; i < bullets.size(); i++)
		this->bullets.push_back(bullets[i]);
}

void Field::control()
{
	vector<Bullet> b = c->shoot(img.getBullet_t(), spaceship);
	c->move(spaceship);
	c->runHub();
	addBullets(b);
}

void Field::collision(sf::RenderWindow &window)
{
	for (int i = 0; i < bullets.size(); i++)
		if (bullets[i].getSprite().getPosition().x > window.getSize().x)
			bullets.erase(bullets.begin() + i);
}

Field::~Field()
{
	bullets.~vector();
	spaceship.~Spaceship();
	img.~Img();
	c->~Control();
}