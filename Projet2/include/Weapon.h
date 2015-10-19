#pragma once

#include <iostream>
#include "Bullet.h"
#include "Img.h"
#include "Global.h"


using namespace std;
class Weapon
{
	private:
		int level;
		int bulletQty;
		int rate;
		int speed;
		bool enemyWeapon;

	public:
		Weapon();
		Weapon(int);
		int getRate();
		vector<Bullet*> shoot(sf::Texture&, sf::Sprite);
		void setLvl(int);
		~Weapon();
};

#endif