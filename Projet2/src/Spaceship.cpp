#include "../include/spaceship.h"

Spaceship::Spaceship() : anim(0, 0) {}

Spaceship::Spaceship(sf::Texture &t) : anim(0,0), weapon(Weapon())
{
	sprite.setTexture(t);
	sprite.setTextureRect(sf::IntRect(anim.x, anim.y, 100, 94));
	sprite.setPosition(100, 100);
}

sf::Sprite &Spaceship::getSprite()
{
	return sprite;
}

Weapon &Spaceship::getWeapon()
{
	return weapon;
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
			sprite.move(0, -5);
			break;
		case 2:
			if (anim.y != 1)
			{
				anim.x = 0;
				anim.y = 1;
			}
			sprite.move(0, 5);
			break;
		case 3:
			anim.y = 0;
			sprite.move(-5, 0);
			break;
		case 4:
			anim.y = 0;
			sprite.move(5, 0);
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