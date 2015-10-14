#pragma region includes
#include <iostream>
#include <../include/SFML/Graphics.hpp>
#include "../include/myo/libmyo.h"
#include "../include/Field.h"
#pragma endregion includes

#pragma region variables
sf::RenderWindow window;
Field field;
#pragma endregion variables

using namespace std;

int main()
{
	window.create(sf::VideoMode(800, 600), "EsigInvaders");
	window.setFramerateLimit(60);

	field = Field();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		field.control();
		field.collision(window);

		window.clear();
		for (int i = 0; i < field.getBullets().size(); i++)
		{
			field.getBullets()[i].move();
			window.draw(field.getBullets()[i].getShape());
		}
		window.draw(field.getSpaceship().getShape());
		window.display();
	}

	return 0;
}