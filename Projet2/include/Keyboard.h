#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

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
		vector<Bullet> shoot(sf::Texture&, Spaceship&);
		~Keyboard();
};

#endif