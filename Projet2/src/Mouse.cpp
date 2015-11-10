#include "..\include\Mouse.h"


Mouse::Mouse()
{
}

bool Mouse::mouseOver(sf::RenderWindow &window, sf::Sprite &button)
{
	if (sf::Mouse::getPosition(window).x > button.getGlobalBounds().left &&
		sf::Mouse::getPosition(window).x < button.getGlobalBounds().left + button.getGlobalBounds().width &&
		sf::Mouse::getPosition(window).y > button.getGlobalBounds().top &&
		sf::Mouse::getPosition(window).y < button.getGlobalBounds().top + button.getGlobalBounds().height)
	{
		return true;
	}
	else
		return false;
}


Mouse::~Mouse()
{
}
