#pragma once
#include "Spaceship.h"
#include "Boss.h"
#include "Control.h"
#include <string>
#include "Resources.h"

class GameHub
{
	private:
		int HUB_HEIGHT = 20;
		sf::Text scoreText;
		sf::Text healthText;
		sf::RectangleShape healthBarOutline, healthBar;
		sf::Text bossHealthText;
		sf::RectangleShape bossHealthBarOutline, bossHealthBar;
		sf::Color outlineColor = sf::Color(107, 111, 107, 255);
		std::string playerPseudo;
	public:
		GameHub(Resources& res, int width);
		~GameHub();
		void resetHub();
		std::string getPlayerPseudo();
		void setPlayerPseudo(sf::RenderWindow* window, sf::Texture& bg, int score, Control* c, Resources &res);
		void updateHub(sf::RenderWindow* window, Spaceship *spaceship, Boss* boss, int score);
};