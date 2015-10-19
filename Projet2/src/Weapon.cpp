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

vector<Bullet*> Weapon::shoot(sf::Texture &texture, sf::Sprite s)
{
	vector<Bullet*> b;
	
	for (int i = 1; i <= bulletQty; i++)
		b.push_back(new Bullet(texture, sf::Vector2f(s.getPosition().x, s.getPosition().y + s.getTextureRect().height * i / (bulletQty + 1) - texture.getSize().y / 2), speed, enemyWeapon));

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
			speed = 10;
			break;
		case 2:
			bulletQty = 2;
			rate = 3;
			speed = 12;
			break;
		case 3:
			bulletQty = 2;
			rate = 5;
			speed = 14;
			break;
		case 4:
			bulletQty = 4;
			rate = 5;
			speed = 16;
			break;
		case 5:
			bulletQty = 5;
			rate = 6;
			speed = 20;
			break;
	}
}

Weapon::~Weapon(){}