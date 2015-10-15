#include "../include/Control.h"
#include "../include/Field.h"

Control::Control() : compteurSpace(1) {}

void Control::arrow(Spaceship &s)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
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
	else
		s.move(0);
}

vector<Bullet> Control::space(sf::Texture &texture, Spaceship &s)
{
	vector<Bullet> b;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (60 / compteurSpace == s.getWeapon().getRate())
		{
			vector<Bullet> bu = s.getWeapon().shoot(texture, s.getSprite().getPosition());
			compteurSpace = 1;
			return bu;
		}
		else
			compteurSpace++;
	}

	return b;
}

Control::~Control() {}