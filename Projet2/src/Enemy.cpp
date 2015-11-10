#include "..\include\Enemy.h"

void Enemy::switchFps()
{
	if (anim.y > 3)
		anim.y = 0;
	if (!pony) {
		if (anim.x < 2)
			sprite.setTextureRect(sf::IntRect(100 * anim.x, 94 * anim.y, 100, 94));
		else
			sprite.setTextureRect(sf::IntRect(86 + 57 * anim.x, 94 * anim.y, 57, 94));
	}
	else {
		sprite.setTextureRect(sf::IntRect(100 * anim.x, 94 * anim.y, 100, 94));
	}
	

	anim.y++;
}

Enemy::Enemy(sf::Texture &t, sf::Texture &expText,sf::SoundBuffer& expBuffer, sf::Vector2f pos, TypeEnemy * Typenemy, int type, bool pony) : SpaceObject(t, expText,expBuffer, 5, 3), compteurEnemy(1)
{
	this->pony = pony;
	this->health = Typenemy->getLife();
	this->rate = Typenemy->getRate();
	this->speed = Typenemy->getSpeed();
	this->laserSpeed = Typenemy->getLaserSpeed();
	this->laserQty = Typenemy->getLaserQty();
	this->dommage = Typenemy->getDommage();
	this->anim = sf::Vector2i(type, 0);
	std::cout << "Value pony" <<pony <<endl;
	if (!pony) {
		if (anim.x < 2)
			sprite.setTextureRect(sf::IntRect(anim.x * 100, anim.y, 100, 94));
		else
			sprite.setTextureRect(sf::IntRect(86 + anim.x * 57, anim.y, 57, 94));
	}
	else {
		sprite.setTextureRect(sf::IntRect(anim.x * 100, anim.y, 100, 94));
	}



	this->score = Typenemy->getScore();
	sprite.setPosition(pos);
}

int Enemy::getScore() {
	return score;
}

void Enemy::move()
{
	sprite.move(-speed, 0);
}

vector<Laser*> Enemy::shoot(sf::Texture &texture)
{
	vector<Laser*> l;

	if (compteurEnemy == 60 / rate)
	{
		for (int i = 1; i <= laserQty; i++)
			l.push_back(new Laser(texture,i,this->laserQty,this->sprite, this->laserSpeed, this->dommage));

		compteurEnemy = 1;
		return l;
	}
	else
		compteurEnemy++;

	return l;
}

Enemy::~Enemy()
{
	std::cout << "Enemy died." << std::endl;
}

int Enemy::getDommage() {
	return this->dommage;
}