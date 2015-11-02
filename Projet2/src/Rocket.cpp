#include "..\include\Rocket.h"

Rocket::Rocket() : Bullet() {};

Rocket::Rocket(sf::Texture &t, sf::Vector2f pos, int spd, int dommage) : Bullet(t, pos, spd, dommage)
{
	sprite.setScale(0.8, 0.8);
}

void Rocket::switchFps()
{
	if (anim > 3)
		anim = 0;

	sprite.setTextureRect(sf::IntRect(49 * anim, 0, 49, 19));

	anim++;
}


Rocket::~Rocket()
{
}
