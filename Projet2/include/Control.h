#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <iostream>
#include "../include/Spaceship.h"

class Control
{
	private:
		int compteurSpace;

	public:
		Control();
		void arrow(Spaceship&);
		vector<Bullet> space(sf::Texture&, Spaceship&);
		~Control();
};

#endif