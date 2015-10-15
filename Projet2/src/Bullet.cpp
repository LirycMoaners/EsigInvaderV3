#include "../include/Bullet.h"

Bullet::Bullet() : speed(0), anim(0){}

Bullet::Bullet(sf::Texture &t, sf::Vector2f pos, int spd) : speed(spd), anim(0)
{
	sprite.setTexture(t);
	sprite.setTextureRect(sf::IntRect(anim, 0, 49, 19));
	sprite.setPosition(pos);
}

Bullet::Bullet(const Bullet &b)
{
	anim = b.anim;
	sprite = b.sprite;
	speed = b.speed;
}

sf::Sprite &Bullet::getSprite()
{
	return sprite;
}

void Bullet::move()
{
	sprite.move(speed, 0);
}

void Bullet::switchFps()
{
	if (anim > 3)
		anim = 0;

	sprite.setTextureRect(sf::IntRect(49 * anim, 0, 49, 19));

	anim++;
}

Bullet::~Bullet()
{
	
}
