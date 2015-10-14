#include "../include/Control.h"
#include "../include/Field.h"

Control::Control() : compteurSpace(1) {}

void Control::arrow(Spaceship &s)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		s.move(1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		s.move(2);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		s.move(3);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		s.move(4);
}

vector<Bullet> Control::space(Spaceship &s)
{
	vector<Bullet> b;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (60 / compteurSpace == s.getWeapon().getRate())
		{
			b = s.getWeapon().shoot(s.getShape().getPosition());
			compteurSpace = 1;
		}
		else
			compteurSpace++;
	}

	return b;
}