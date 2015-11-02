#include "..\include\SpaceObject.h"

SpaceObject::SpaceObject(sf::Texture &t,int health, int speed)
{
	//Create graphical object
	this->sprite.setTexture(t);

	//Set properties values
	this->health = health;
	this->speed = speed;
}
SpaceObject::SpaceObject() {}

void SpaceObject::takeDommage(int dommage) {
	std::cout << "Object health: " << health << std::endl;
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
