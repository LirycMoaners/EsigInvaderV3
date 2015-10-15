#ifndef IMG_H_INCLUDED
#define IMG_H_INCLUDED

#include <../include/SFML/Graphics.hpp>

class Img
{
	private:
		sf::Texture spaceship_t;
		sf::Texture bullet_t;
		sf::Texture background_t;
	public:
		Img();
		sf::Texture &getSpaceship_t();
		sf::Texture &getBullet_t();
		sf::Texture &getBackground_t();
		~Img();
};

#endif