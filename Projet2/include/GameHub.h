#pragma once
#include "Spaceship.h"
#include "Boss.h"

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
		sf::Font arial;
		std::string playerPseudo;

	public:
		GameHub();
		~GameHub();
		void resetHub();
		void setPlayerPseudo(sf::RenderWindow* window, sf::Texture& bg, int score);
		void updateHub(sf::RenderWindow* window, Spaceship *spaceship, Boss* boss, int score);
};