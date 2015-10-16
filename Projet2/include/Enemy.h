#pragma once
#include <SFML\Graphics.hpp>
#include<iostream>

class Enemy
{
private:
	sf::Sprite shape;
	int health;
	float speed;
public:
	Enemy();
	Enemy(float, float, sf::Texture&);
	sf::Sprite getShape();
	int getHealth();
	float getSpeed();
	void setSpeed(float);
	void move();

	~Enemy();
};

