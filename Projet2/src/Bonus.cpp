#include "..\include\Bonus.h"

Bonus::Bonus(sf::Texture t, sf::Vector2f pos) : anim(0), speed(10)
{
	effect = rand() % 1;
	if (effect == 0)
		effect = -1;
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
}
