#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <iostream>
#include "Spaceship.h"

class Control
{
public:
	Control(){}
	virtual ~Control(){}
	virtual bool getStatus() = 0;
	virtual void move(Spaceship&) = 0;
	virtual vector<Bullet> shoot(sf::Texture&, Spaceship&)= 0;
};

#endif

