#pragma region includes
#include <iostream>
#include <../include/SFML/Graphics.hpp>
#include "../include/myo/libmyo.h"
#include "../include/Field.h"
#pragma endregion includes

using namespace std;

int main()
{
	sf::RenderWindow window;
	sf::Clock clk;
	int fpsCount = 0;
	int fpsSwitch = 200;
	Field field;

	window.create(sf::VideoMode(800, 600), "EsigInvaders");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		field.collision(window);
		field.control();

		if (fpsCount >= fpsSwitch)
		{
			field.getSpaceship().switchFps();
			for (int i = 0; i < field.getBullets().size(); i++)
			{
				field.getBullets()[i].switchFps();
			}
			fpsCount = 0;
		}
		else
			fpsCount += clk.restart().asMilliseconds();

		window.clear();
		for (int i = 0; i < field.getBullets().size(); i++)
		{
			field.getBullets()[i].move();
			window.draw(field.getBullets()[i].getSprite());
		}
		window.draw(field.getSpaceship().getSprite());
		window.display();
	}

	return 0;
}