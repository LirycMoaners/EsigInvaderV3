#pragma once
#include <iostream>
#include "Spaceship.h"
#include "Global.h"

class Control
{
public:
	//virtual Control(){}
	virtual ~Control(){}
	virtual bool getStatus() = 0;
	virtual void runHub() = 0;
	virtual void move(Spaceship*) =0 ;
	virtual vector<Bullet*> shoot(sf::Texture&, Spaceship*) = 0;
};


