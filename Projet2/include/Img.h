#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
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
		sf::Texture settingIco_t;
		sf::Texture explosion_t;
		sf::Texture button_t;
		sf::Texture bonus_t;
		sf::Texture button_arrow_t;
		sf::Texture about_t;
		sf::Texture authors_t;

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
		sf::Texture &getSettingIco();
		sf::Texture &getButtonArrow_t();
		sf::Texture &getBonus_t();
		sf::Texture &getAuthors_t();
		sf::Texture &getAbout_t();
		void setBoss_t(std::string name);
		void setEnemy_t(std::string name);
		void setSpaceship_t(std::string name);
		~Img();
};