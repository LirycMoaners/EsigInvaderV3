#pragma once

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
class Img
{
	private:
		sf::Texture spaceship_t;
		sf::Texture rocket_t;
		sf::Texture laser_t;
		sf::Texture background_t;
		sf::Texture enemy_t;
		sf::Texture boss_t;
		sf::Texture home_t;
	public:
		Img();
		sf::Texture &getSpaceship_t();
		sf::Texture &getRocket_t();
		sf::Texture &getLaser_t();
		sf::Texture &getBackground_t();
		sf::Texture &getEnemy_t();
		sf::Texture &getBoss_t();
		sf::Texture &getHome_t();
		void setBoss_t(string name);
		~Img();
};