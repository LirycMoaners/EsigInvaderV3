#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include <iostream>
#include "../include/Bullet.h"
#include "../include/Img.h"


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
		vector<Bullet> shoot(sf::Texture&, sf::Vector2f);
		void setLvl(int);
		~Weapon();
};

#endif