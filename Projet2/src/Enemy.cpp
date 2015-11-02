#include "..\include\Enemy.h"
/*Enemy::Enemy(float startX, float startY, sf::Texture& texture):SpaceObject(texture,5,3),weapon(Weapon(true))
{
	if (startY < 0) {
		startY = 0;
	}
	this->sprite.setPosition(startX, startY);
	//this->shape.setTextureRect(sf::IntRect(0, 0, 100, 94));
	int result = rand() % 2;
	if (result) {
		moveDown = false;
	}
	else {
		moveDown = true;
	}
	
}*/

void Enemy::switchFps()
{
	if (anim.y > 3)
		anim.y = 0;

	if (anim.x < 2)
		sprite.setTextureRect(sf::IntRect(100 * anim.x, 94 * anim.y, 100, 94));
	else
		sprite.setTextureRect(sf::IntRect(86 + 57 * anim.x, 94 * anim.y, 57, 94));

	anim.y++;
}

Enemy::Enemy(sf::Texture &t, sf::Vector2f pos) : SpaceObject(t, 5, 3), anim(1 - 1, 0), compteurEnemy(1)
{
	if (anim.x < 2)
		sprite.setTextureRect(sf::IntRect(anim.x * 100, anim.y, 100, 94));
	else
		sprite.setTextureRect(sf::IntRect(86 + anim.x * 57, anim.y, 57, 94));
	sprite.setPosition(pos);
	setLvl(1);
}

Enemy::Enemy(sf::Texture &t, sf::Vector2f pos, int lvl = 1, int type = 1) : SpaceObject(t, 5, 3), anim(type - 1, 0), compteurEnemy(1)
{
	if (anim.x < 2)
		sprite.setTextureRect(sf::IntRect(anim.x * 100, anim.y, 100, 94));
	else
		sprite.setTextureRect(sf::IntRect(86 + anim.x * 57, anim.y, 57, 94));
	sprite.setPosition(pos);
	setLvl(lvl);
	
}

bool Enemy::getType() {
	return this->boss;
}

void Enemy::move()
{
	sprite.move(speed, 0);

	//Change direction when enemy it the border of the window
	/*if (sprite.getPosition().y < 0 || (sprite.getPosition().y + sprite.getTextureRect().height) > WINDOW_HEIGHT)
		moveDown = !moveDown;

	if (moveDown)
		sprite.move(0, speed);
	else
		sprite.move(0, -speed);*/
}

void Enemy::setLvl(int lvl)
{
	switch (lvl)
	{
	case 1:
		speed = -1;
		laserQty = 1;
		rate = 1;
		dommage = 5;
		laserSpeed = 10;
		break;
	case 2:
		speed = -1;
		laserQty = 2;
		rate = 1;
		dommage = 5;
		laserSpeed = 12;
		break;
	case 3:
		speed = -2;
		laserQty = 2;
		rate = 2;
		dommage = 5;
		laserSpeed = 14;
		break;
	case 4:
		speed = -2;
		laserQty = 4;
		dommage = 5;
		rate = 2;
		laserSpeed = 16;
		break;
	case 5:
		speed = -3;
		laserQty = 5;
		dommage = 5;
		rate = 3;
		laserSpeed = 18;
		break;
	}
}

vector<Laser*> Enemy::shoot(sf::Texture &texture)
{
	vector<Laser*> l;

	if (compteurEnemy == 60 / rate)
	{
		for (int i = 1; i <= laserQty; i++)
			l.push_back(new Laser(texture, sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + sprite.getTextureRect().height * i / (laserQty + 1) - texture.getSize().y / 12), laserSpeed, dommage));

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