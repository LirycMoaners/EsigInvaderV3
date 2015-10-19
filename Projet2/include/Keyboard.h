#pragma once

#include <iostream>
#include "Spaceship.h"
#include "Control.h"
#include "Global.h"

class Keyboard : public Control
{
	private:
		int compteurSpace;
	public:
		Keyboard();
		bool getStatus();
		void runHub();
		void move(Spaceship*);
		vector<Bullet*> shoot(sf::Texture&, Spaceship*);
		~Keyboard();
};

#endif