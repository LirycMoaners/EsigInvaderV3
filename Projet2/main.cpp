#pragma region includes
#include <SFML/Graphics.hpp>
#include <iostream>
#include "terrain.h"
#pragma endregion includes

#pragma region variables
sf::RenderWindow window;
int framerate = 60;
Terrain terrain;
#pragma endregion variables

#pragma region prototypes
void deplacement();
int tir(int compteur);
#pragma endregion prototypes

using namespace std;

int main()
{
	window.create(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(framerate);
	
	terrain = Terrain();
	int compteur = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		compteur = tir(compteur);
		deplacement();
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

void deplacement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		terrain.getSpaceship().move(1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		terrain.getSpaceship().move(2);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		terrain.getSpaceship().move(3);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		terrain.getSpaceship().move(4);
}

int tir(int compteur)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (framerate / compteur == terrain.getSpaceship().getWeapon().getRate())
		{
			vector<Bullet> b = terrain.getSpaceship().getWeapon().shoot(terrain.getSpaceship().getShape().getPosition());
			for (int i = 0; i < b.size(); i++)
				terrain.addBullet(b[i]);
			compteur = 1;
		}
		else
			compteur++;
	}

	return compteur;
}