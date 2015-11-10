#include "../include/spaceship.h"

Spaceship::Spaceship(sf::Texture &t, sf::Texture &expt, sf::SoundBuffer& expBuffer) : anim(0,0), weapon(Weapon()),SpaceObject(t,expt,expBuffer,HEALTH_MAX = 1500,5)
{
	sprite.setTexture(t);
	sprite.setTextureRect(sf::IntRect(anim.x, anim.y, 100, 94));
	sprite.setScale(sf::Vector2f(0.6, 0.6));
	sprite.setPosition(100, 100);
}


Weapon &Spaceship::getWeapon()
{
	return weapon;
}


void Spaceship::setHealth(int health, bool changeMax) 
{
	if (changeMax)
		HEALTH_MAX = health;

	if((this->health + health) < HEALTH_MAX)
		this->health += health;
	else
		this->health = HEALTH_MAX;
}
void Spaceship::move(int dir)
{
	switch (dir)
	{
		case 0:
			anim.y = 0;
			break;
		case 1:
			if (anim.y != 2)
			{
				anim.x = 0;
				anim.y = 2;
			}
			sprite.move(0, -speed);
			break;
		case 2:
			if (anim.y != 1)
			{
				anim.x = 0;
				anim.y = 1;
			}
			sprite.move(0, speed);
			break;
		case 3:
			anim.y = 0;
			sprite.move(-speed, 0);
			break;
		case 4:
			anim.y = 0;
			sprite.move(speed, 0);
			break;
	}	
}

void Spaceship::switchFps()
{
	if (anim.x > 3 && anim.y == 0)
		anim.x = 0;

	if (anim.x > 1 && anim.y != 0)
		anim.x = 1;

	sprite.setTextureRect(sf::IntRect(100 * anim.x, 94 * anim.y, 100, 94));

	anim.x++;
}

Spaceship::~Spaceship()
{
	weapon.~Weapon();
}

int Spaceship::getHealthMax() { return this->HEALTH_MAX; }