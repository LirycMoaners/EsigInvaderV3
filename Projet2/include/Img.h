#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"
#include <string>
using namespace std;
class Img
{
	private:
		sf::Texture spaceship_t;
		sf::Texture bullet_t;
		sf::Texture background_t;
		sf::Texture enemy_t;
		sf::Texture boss_t;
	public:
		Img();
		sf::Texture &getSpaceship_t();
		sf::Texture &getBullet_t();
		sf::Texture &getBackground_t();
		sf::Texture &getEnemy_t();
		sf::Texture &getBoss_t();
		void setBoss_t(string name);
		~Img();
};