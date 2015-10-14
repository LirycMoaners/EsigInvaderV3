#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include "bullet.h"

using namespace std;
class Weapon
{
	private:
		int level;
		int bulletQty;
		int rate;
	public:
		Weapon();
		Weapon(int);
		int getRate();
		vector<Bullet> shoot(sf::Vector2f);
		void setLvl(int);
		~Weapon();
};

#endif