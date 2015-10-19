#include "..\include\SpaceObject.h"

SpaceObject::SpaceObject(sf::Texture &t,int health, int speed)
{
	//Create graphical object
	sprite.setTexture(t);

	//Set properties values
	this->health = health;
	this->speed = speed;
}

void SpaceObject::takeDommage(int dommage) {
	this->health -= dommage;
}
bool SpaceObject::isAlive() {
	return ((this->health > 0) ? true : false);
}

SpaceObject::~SpaceObject()
{
}

sf::Sprite &SpaceObject::getSprite()
{
	return this->sprite;
}

int SpaceObject::getHealth() { return this->health; };
int SpaceObject::getSpeed() { return this->speed; };
