#pragma once
#include <iostream>
#include <vector>
#include "Spaceship.h"

//TODO Commenter cette classe
class Control
{
public:
	//virtual Control(){}
	virtual ~Control(){}
	virtual bool getStatus() = 0;
	virtual void runHub() = 0;
	virtual void move(Spaceship*) = 0 ;
	virtual std::vector<Rocket*> shoot(sf::Texture&, Spaceship*) = 0;
	virtual bool quit() = 0;
};


