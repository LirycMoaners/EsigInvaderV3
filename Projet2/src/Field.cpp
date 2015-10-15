#include "../include/Field.h"

Field::Field(bool available) : bullets(NULL)
{
	img = Img();
	if (available) {
		c = new Armband();
		if (!c->getStatus()) {
			delete c;
			c = new Keyboard();
		}
	}
	else {
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

	if (spaceship.getSprite().getPosition().x < 0)
		spaceship.getSprite().setPosition(0, spaceship.getSprite().getPosition().y);
	else if (spaceship.getSprite().getPosition().x + spaceship.getSprite().getTextureRect().width > window.getSize().x)
		spaceship.getSprite().setPosition(window.getSize().x - spaceship.getSprite().getTextureRect().width, spaceship.getSprite().getPosition().y);
	
	if (spaceship.getSprite().getPosition().y < 0)
		spaceship.getSprite().setPosition(spaceship.getSprite().getPosition().x, 0);
	else if (spaceship.getSprite().getPosition().y + spaceship.getSprite().getTextureRect().height > window.getSize().y)
		spaceship.getSprite().setPosition(spaceship.getSprite().getPosition().x, window.getSize().y - spaceship.getSprite().getTextureRect().height);
}

Field::~Field()
{
	bullets.~vector();
	spaceship.~Spaceship();
	c->~Control();
}