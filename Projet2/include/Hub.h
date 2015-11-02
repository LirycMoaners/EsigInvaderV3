#pragma once
#ifndef __HUB_H__
#define __HUB_H__
#include <SFML\Graphics.hpp>
#include "Spaceship.h"
#include "Global.h"

class Hub
{
	private:
		int HUB_HEIGHT = 20;
		sf::Text healthText, shieldText;
		sf::RectangleShape healthBarOutline, healthBar;
		sf::RectangleShape shieldBarOutline, shieldBar;
		sf::Color outlineColor = sf::Color(107, 111, 107, 255);
		sf::Font arial;

	public:
		Hub();
		void updateHub(sf::RenderWindow& window, Spaceship &spaceship);
};

#endif // !__HUB_H__

