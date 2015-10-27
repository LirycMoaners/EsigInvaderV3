#pragma once

#include <iostream>
#include "Rocket.h"
#include "Img.h"


using namespace std;
class Weapon
{
	private:
		int level;
		int rocketQty;
		int rate;
		int speed;
		bool enemyWeapon;
		int dommage;

	public:
		Weapon(bool enemy = false);
		Weapon(int, bool enemy = false);
		int getRate();
		vector<Rocket*> shoot(sf::Texture&, sf::Sprite);
		void setLvl(int);
		int getDommage();
		~Weapon();
};