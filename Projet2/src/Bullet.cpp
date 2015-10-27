#include "../include/Bullet.h"

Bullet::Bullet() : speed(0), anim(0){}

Bullet::Bullet(sf::Texture &t, sf::Vector2f pos, int spd) : speed(spd), anim(0)
{
	sprite.setTexture(t);
	sprite.setTextureRect(sf::IntRect(anim, 0, 49, 19));
	sprite.setPosition(pos);
	//enemyBullet = enemy;

	//if (enemy)
	//	sprite.rotate(180); //Change orientation of the bullet for enemies
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
	//Change direction of the bullet if it's an enemy who fire
	//if(enemyBullet)
	//	sprite.move(-speed, 0);
	//else
		sprite.move(speed, 0);
}

bool Bullet::isEnemyBullet() { return enemyBullet; }

void Bullet::switchFps()
{
	if (anim > 3)
		anim = 0;

	sprite.setTextureRect(sf::IntRect(49 * anim, 0, 49, 19));

	anim++;
}

Bullet::~Bullet()
{
	std::cout << "Destructeur Bullet call" << std::endl;
}
