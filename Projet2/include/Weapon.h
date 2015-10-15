#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include "Bullet.h"
#include "Img.h"


using namespace std;
class Weapon
{
	private:
		int level;
		int bulletQty;
		int rate;
		int speed;
	public:
		Weapon();
		Weapon(int);
		int getRate();
		vector<Bullet> shoot(sf::Texture&, sf::Sprite);
		void setLvl(int);
		~Weapon();
};

#endif