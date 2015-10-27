#pragma once

#include <../include/SFML/Graphics.hpp>

class Mouse
{
	public:
		Mouse();
		~Mouse();
		bool mouseOver(sf::RenderWindow&, sf::RectangleShape&);
};

