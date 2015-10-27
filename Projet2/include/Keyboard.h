#pragma once

#include <iostream>
#include "Spaceship.h"
#include "Control.h"

class Keyboard : public Control
{
	private:
		int compteurSpace;
	public:
		Keyboard();
		bool getStatus();
		void runHub();
		void move(Spaceship&);
		vector<Rocket*> shoot(sf::Texture&, Spaceship&);
		bool quit();
		~Keyboard();
};