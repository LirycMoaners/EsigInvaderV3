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

	if (health > 0)
		return true;
	else
		return isExplosing();
}

SpaceObject::~SpaceObject() {}

sf::Sprite &SpaceObject::getSprite()
{
	return this->sprite;
}

int SpaceObject::getHealth() { return this->health; };
int SpaceObject::getSpeed() { return this->speed; };

bool SpaceObject::isExplosing()
{
	if (explosionFrameCounter == 0)
	{
		//Explosion frame update limiter
		explosionFrameSpeed = new sf::Clock();
		explosionSprite = new sf::Sprite();

		//Change objects texture to explosion texture
		//explosionSprite->setTexture();
		explosionSprite->setScale(sprite.getScale());
		explosionSprite->setPosition(sprite.getPosition());
		explosionSprite->setTextureRect(sf::IntRect(94 * explosionFrameCounter, 0, 94, 100));
		explosionFrameCounter++;
		return true;
	}
	else if (explosionFrameCounter < 8 && explosionFrameSpeed->getElapsedTime().asMilliseconds() > 100)
	{
		explosionSprite->setTextureRect(sf::IntRect(94 * explosionFrameCounter, 0, 94, 100));
		explosionSprite->setPosition(sprite.getPosition());
		explosionFrameSpeed->restart();
		explosionFrameCounter++;
		return true;
	}
	else if (explosionFrameCounter >= 8)
	{
		delete explosionFrameSpeed;
		return false;
	}
}
