#include "..\include\Bonus.h"

Bonus::Bonus(sf::Texture &t, sf::Vector2f pos) : anim(0), speed(2)
{
	effect = rand() % 2;
	if (effect == 0)
		effect = -1;

	sprite.setTexture(t);
	if (effect == 1)
		sprite.setTextureRect(sf::IntRect(0,0,30,30));
	else
		sprite.setTextureRect(sf::IntRect(0,30,30,30));

	sprite.setPosition(pos.x - sprite.getGlobalBounds().width / 2, pos.y - sprite.getGlobalBounds().height / 2);
}

int Bonus::getEffect(){
	return effect;
}

sf::Sprite &Bonus::getSprite()
{
	return sprite;
}

void Bonus::move(){
	sprite.move(-speed, 0);
}

void Bonus::switchFps()
{
	if (anim > 2)
		anim = 0;

	if (effect == 1)
		sprite.setTextureRect(sf::IntRect(30 * anim, 0, 30, 30));
	else
		sprite.setTextureRect(sf::IntRect(30 * anim, 30, 30, 30));

	anim++;
}

Bonus::~Bonus()
{
	std::cout << "Bonus destructor" << std::endl;
}
