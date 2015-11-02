#include "..\include\Laser.h"

Laser::Laser() : Bullet() {};

Laser::Laser(sf::Texture &t,int idLaser, int nbLaser, sf::Sprite sp, int spd, int dommage) : Bullet(t,idLaser,nbLaser,sp, -spd, dommage)
{
	Bullet::sprite.setTextureRect(sf::IntRect(0, anim, 31, 11));
}

void Laser::switchFps()
{
	if (anim > 3)
		anim = 0;

	sprite.setTextureRect(sf::IntRect(0, 11 * anim, 31, 11));

	anim++;
}

Laser::~Laser()
{
}
