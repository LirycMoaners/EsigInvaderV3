#include "..\include\Rocket.h"

Rocket::Rocket() : Bullet() {};

Rocket::Rocket(sf::Texture &t, int idRocket, int nbRocket, sf::Sprite sp, int spd, int dommage) : Bullet(t, idRocket, nbRocket, sp, spd, dommage, 0.6) {}

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
