#pragma once
#include "Spaceship.h"

class GameHub
{
	private:
		int HUB_HEIGHT = 20;
		sf::Text healthText;
		sf::RectangleShape healthBarOutline, healthBar;
		sf::Color outlineColor = sf::Color(107, 111, 107, 255);
		sf::Font arial;

	public:
		GameHub();
		~GameHub();
		void updateHub(sf::RenderWindow* window, Spaceship &spaceship);
};