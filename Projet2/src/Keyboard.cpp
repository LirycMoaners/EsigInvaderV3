#include "../include/Keyboard.h"
#include "../include/Field.h"

Keyboard::Keyboard() : compteurSpace(1) {}

bool Keyboard::getStatus() {
	return false;
}

void Keyboard::runHub() {

}

void Keyboard::move(Spaceship *s)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			s->move(1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			s->move(2);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			s->move(3);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			s->move(4);
	}
	else
		s->move(0);
}

vector<Bullet*> Keyboard::shoot(sf::Texture &texture, Spaceship *s)
{
	vector<Bullet*> b;
	sf::Vector2f pos;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (compteurSpace == 60 / s->getWeapon().getRate()) 
		{
			vector<Bullet*> bu = s->getWeapon().shoot(texture, s->getSprite());
			compteurSpace = 1;
			return bu;
		}
		else
			compteurSpace++;
	}
	else{
		if (compteurSpace == 60 / s->getWeapon().getRate())
			compteurSpace = 60 / s->getWeapon().getRate();
		else
			compteurSpace++;
	}

	return b;
}

Keyboard::~Keyboard() {}