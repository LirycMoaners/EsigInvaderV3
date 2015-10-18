#pragma once
#include <SFML\Graphics.hpp>
#include<iostream>

class Enemy
{
private:
	sf::Sprite shape;
	float speed;
	
protected : 
	int health;
	int dommage;
public:
	Enemy();
	Enemy(float, float, sf::Texture&);
	sf::Sprite getShape();
	void setHealth(int);
	void setDommage(int);
	int getDommage();
	int getHealth();
	float getSpeed();
	void setSpeed(float);
	void move();

	~Enemy();
};

