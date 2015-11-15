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

int Mouse::mouseOver(sf::RenderWindow &window, sf::Sprite &button, int size)
{
	if (sf::Mouse::getPosition(window).x > button.getGlobalBounds().left && 
		sf::Mouse::getPosition(window).x < button.getGlobalBounds().left + size &&
		sf::Mouse::getPosition(window).y > button.getGlobalBounds().top &&
		sf::Mouse::getPosition(window).y < button.getGlobalBounds().top + button.getGlobalBounds().height)
	{
		return 2;
	}
	else if (sf::Mouse::getPosition(window).x > button.getGlobalBounds().left + button.getGlobalBounds().width - size &&
			sf::Mouse::getPosition(window).x < button.getGlobalBounds().left + button.getGlobalBounds().width &&
			sf::Mouse::getPosition(window).y > button.getGlobalBounds().top &&
			sf::Mouse::getPosition(window).y < button.getGlobalBounds().top + button.getGlobalBounds().height)
	{
		return 1;
	}
	else
		return 0;
}


Mouse::~Mouse()
{
}
