#include "Menu.h"
#include "Mouse.h"

Menu::Menu(int width, int height, string title, Resources &res) : Windows(width, height, title)
{
	background.setTexture(&res.getImg()->getHome_t());
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setPosition(0, 0);

	//Menu buttons
	// Création du bouton Start Game
	
	// Définition du rectangle autour du texte
	buttonStart.setTexture(res.getImg()->getButton_t());
	buttonStart.setTextureRect(sf::IntRect(0, 0, 295, 85));
	buttonStart.setPosition(WINDOW_WIDTH / 2 - buttonStart.getGlobalBounds().width / 2, 470);

	// Définition du rectangle autour du texte
	buttonQuit.setTexture(res.getImg()->getButton_t());
	buttonQuit.setTextureRect(sf::IntRect(0, 85, 295, 85));
	buttonQuit.setPosition(WINDOW_WIDTH / 2 - buttonQuit.getGlobalBounds().width / 2, 570);
}

void Menu::runWindows()
{
	Mouse mouse;

	while (window->isOpen())
	{
		sf::Event event;

		//Mouse event and menu animations
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		/* Change style of buttons */
		if (mouse.mouseOver(*window, buttonStart))
		{
			//Change color of the button
			buttonStart.setTextureRect(sf::IntRect(0, 170, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				Game(*window,res).runGame();
		}
		else
		{
			//Change color of the button
			buttonStart.setTextureRect(sf::IntRect(0, 0, 295, 85));
		}
		if (mouse.mouseOver(*window, buttonQuit))
		{
			//Change color of the button
			buttonQuit.setTextureRect(sf::IntRect(0, 255, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				window->close();
		}
		else
		{
			//Change color of the button
			buttonQuit.setTextureRect(sf::IntRect(0, 85, 295, 85));
		}
		/* ---------------------------------------------- */

		//Redraw the window
		window->clear();
		window->draw(background);
		window->draw(buttonStart);
		window->draw(buttonQuit);
		window->display();
	}

	window->close();
}

Menu::~Menu() {}