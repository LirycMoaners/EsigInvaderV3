#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
class Img
{
	// définition des textures
	private: 
		sf::Texture spaceship_t;
		sf::Texture rocket_t;
		sf::Texture laser_t;
		sf::Texture background_t;
		sf::Texture enemy_t;
		sf::Texture boss_t;
		sf::Texture home_t;
		sf::Texture explosion_t;
		sf::Texture button_t;
		sf::Texture bonus_t;

	public:
		Img();
		sf::Texture &getSpaceship_t();
		sf::Texture &getRocket_t();
		sf::Texture &getLaser_t();
		sf::Texture &getBackground_t();
		sf::Texture &getExplosion_t();
		sf::Texture &getEnemy_t();
		sf::Texture &getBoss_t();
		sf::Texture &getHome_t();
		sf::Texture &getButton_t();
		sf::Texture &getBonus_t();
		void setBoss_t(string name);
		void setEnemy_t(string name);
		void setSpaceship_t(string name);
		~Img();
};