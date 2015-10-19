#include "..\include\Enemy.h"

Enemy::Enemy(float startX, float startY, sf::Texture& texture):SpaceObject(texture,5,3),weapon(Weapon())
{
	this->sprite.setPosition(startX, startY);
	//this->shape.setTextureRect(sf::IntRect(0, 0, 100, 94));

	moveDown = true;
}

void Enemy::move()
{
	sprite.move(-speed, 0);

	//Change direction when enemy it the border of the window
	if (sprite.getPosition().y < 0 || (sprite.getPosition().y + sprite.getTextureRect().height) > 768)
		moveDown = !moveDown;

	if (moveDown)
		sprite.move(0, speed);
	else
		sprite.move(0, -speed);
}

Enemy::~Enemy()
{
	std::cout << "Enemy died." << std::endl;
}

int Enemy::getDommage() {
	return this->dommage;
}