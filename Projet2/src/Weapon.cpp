#include "../include/weapon.h"

using namespace std;
Weapon::Weapon(bool enemy)
{
	setLvl(1);
	enemyWeapon = enemy; //Weapon owner by an enemy or not
}

Weapon::Weapon(int lvl,bool enemy)
{
	setLvl(lvl);
	enemyWeapon = enemy; //Weapon owner by an enemy or not 
}

int Weapon::getRate()
{
	return rate;
}

vector<Rocket*> Weapon::shoot(sf::Texture &texture, sf::Sprite s)
{
	vector<Rocket*> b;
	
	for (int i = 1; i <= rocketQty; i++)
		b.push_back(new Rocket(texture,i,rocketQty,s, speed, dommage));
		//b.push_back(new Rocket(texture, sf::Vector2f(s.getPosition().x, s.getPosition().y + s.getTextureRect().height * i / (rocketQty + 1) - texture.getSize().y / 2), speed, dommage));

	return b;
}
int Weapon::getDommage() {
	return this->dommage;
}


void Weapon::setLvl(int lvl)
{
	level = lvl;

	switch (level)
	{
		case 1:
			rocketQty = 1;
			rate = 3;
			speed = 10;
			dommage = 250;
			break;
		case 2:
			rocketQty = 2;
			rate = 3;
			speed = 12;
			dommage = 500;
			break;
		case 3:
			rocketQty = 2;
			rate = 5;
			speed = 14;
			dommage = 750;
			break;
		case 4:
			rocketQty = 4;
			rate = 5;
			speed = 16;
			dommage = 1000;
			break;
		case 5:
			rocketQty = 5;
			rate = 6;
			speed = 20;
			dommage = 1500;
			break;
	}
}

Weapon::~Weapon(){}