#pragma once

#include <../include/SFML/Graphics.hpp>

class Mouse
{
	public:
		Mouse();
		~Mouse();
		// D�tecte la souris
		bool mouseOver(sf::RenderWindow&, sf::Sprite&);
};

