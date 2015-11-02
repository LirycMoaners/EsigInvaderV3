#include "Hub.h"

Hub::Hub()
{
	//Create healthbar
	arial.loadFromFile("ressources/arial.ttf");
	healthText.setFont(arial);
	healthText.setCharacterSize(HUB_HEIGHT - 2);
	healthText.setString("Health:");
	healthText.setColor(outlineColor);
	healthText.setPosition(2, 0);
	healthBarOutline.setFillColor(sf::Color::Transparent);
	healthBarOutline.setOutlineThickness(2);
	healthBarOutline.setOutlineColor(outlineColor);
	healthBarOutline.setPosition(healthText.getPosition().x + healthText.getLocalBounds().width + 4, 4);
	healthBarOutline.setSize(sf::Vector2f(1024 / 5, HUB_HEIGHT - 4));
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(healthBarOutline.getPosition());
	healthBar.setSize(sf::Vector2f(1024 / 5, HUB_HEIGHT - 4));
}

void Hub::updateHub(sf::RenderWindow& window, Spaceship& spaceObject)
{
	//Update bar size
	float healthScale = spaceObject.getHealth() > 0 ? ((float)spaceObject.getHealth() / 1000) : 0;
	healthBar.setScale(sf::Vector2f(healthScale, 1));
	healthBar.setFillColor(sf::Color((255 - healthScale * 255), healthScale * 255, 0));

	//Draw component in the windows
	window.draw(healthText);
	window.draw(healthBarOutline);
	window.draw(healthBar);
}