#pragma region includes
#include <SFML/Graphics.hpp>
#include <iostream>
#include "terrain.h"
#pragma endregion includes

#pragma region variables
sf::RenderWindow window;
Terrain terrain;
#pragma endregion variables

using namespace std;

int main()
{
	window.create(sf::VideoMode(800, 600), "EsigInvaders");
	window.setFramerateLimit(60);
	
	terrain = Terrain();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		terrain.control();
		terrain.collision(window);

		window.clear();
		for (int i = 0; i < terrain.getBullets().size(); i++)
		{
			terrain.getBullets()[i].move();
			window.draw(terrain.getBullets()[i].getShape());
		}
		window.draw(terrain.getSpaceship().getShape());
		window.display();
	}

	return 0;
}