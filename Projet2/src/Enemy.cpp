#include "..\include\Enemy.h"

Enemy::Enemy()
{

}
Enemy::Enemy(float startX, float startY, sf::Texture& texture)
{
	this->shape.setTexture(texture);
	this->shape.setPosition(startX, startY);
	//this->shape.setTextureRect(sf::IntRect(0, 0, 100, 94));
	speed = 3;

}

sf::Sprite Enemy::getShape() 
{ 
	return this->shape; 
}
int Enemy::getHealth()
{
	return this->health;
}
float Enemy::getSpeed()
{
	return this->speed;
}
void Enemy::setSpeed(float speed)
{
	this->speed = speed;
}

void Enemy::move()
{
	shape.move(-speed, 0);
}

Enemy::~Enemy()
{
	std::cout << "Enemy died." << std::endl;
}

void Enemy::setHealth(int health) {
	this->health = health;
}
void Enemy::setDommage(int dommage) {
	this->dommage = dommage;
}
int Enemy::getDommage() {
	return this->dommage;
}