#include "../include/weapon.h"

Weapon::Weapon()
{
	setLvl(1);
}

Weapon::Weapon(int lvl)
{
	setLvl(lvl);
}

int Weapon::getRate()
{
	return rate;
}

vector<Bullet> Weapon::shoot(sf::Texture &texture, sf::Vector2f pos)
{
	vector<Bullet> b;
	
	for (int i = 1; i <= bulletQty; i++)
		b.push_back(Bullet(texture, sf::Vector2f(pos.x + 50, pos.y + 100*i / (bulletQty + 1)), 10));

	return b;
}

void Weapon::setLvl(int lvl)
{
	level = lvl;

	switch (level)
	{
		case 1:
			bulletQty = 1;
			rate = 3;
			break;
		case 2:
			bulletQty = 2;
			rate = 3;
			break;
		case 3:
			bulletQty = 2;
			rate = 5;
			break;
		case 4:
			bulletQty = 4;
			rate = 5;
			break;
		case 5:
			bulletQty = 5;
			rate = 6;
			break;
	}
}

Weapon::~Weapon(){}