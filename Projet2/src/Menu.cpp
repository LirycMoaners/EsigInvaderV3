#include "Menu.h"
#include "Mouse.h"

Menu::Menu(int width, int height, string title) : Windows(width, height, title)
{
	arial.loadFromFile("ressources/arial.ttf");
	sf::Vector2f buttonSize(300, 49);

	//Menu buttons
	startText.setFont(arial);
	startText.setCharacterSize(25);
	startText.setString("Start Game");
	startText.setColor(sf::Color::Blue);
	startText.setPosition(WINDOW_WIDTH / 2 - startText.getGlobalBounds().width / 2, 400);
	buttonStart.setFillColor(sf::Color::Transparent);
	buttonStart.setOutlineColor(sf::Color::Blue);
	buttonStart.setOutlineThickness(2);
	buttonStart.setPosition(sf::Vector2f(startText.getPosition().x - (buttonSize.x - startText.getLocalBounds().width) / 2,
		startText.getPosition().y - (buttonSize.y - startText.getLocalBounds().height) / 3));
	buttonStart.setSize(buttonSize);

	quitText.setFont(arial);
	quitText.setCharacterSize(25);
	quitText.setString("Quit Game");
	quitText.setColor(sf::Color::Blue);
	quitText.setPosition(WINDOW_WIDTH / 2 - quitText.getGlobalBounds().width / 2, 500);
	buttonQuit.setFillColor(sf::Color::Transparent);
	buttonQuit.setOutlineColor(sf::Color::Blue);
	buttonQuit.setOutlineThickness(2);
	buttonQuit.setPosition(sf::Vector2f(quitText.getPosition().x - (buttonSize.x - quitText.getLocalBounds().width) / 2,
		quitText.getPosition().y - (buttonSize.y - quitText.getLocalBounds().height) / 3));
	buttonQuit.setSize(buttonSize);
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
			startText.setColor(sf::Color::Red);
			buttonStart.setOutlineColor(sf::Color::Red);

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				Game(*window).runGame();
		}
		else
		{
			//Change color of the button
			startText.setColor(sf::Color::Blue);
			buttonStart.setOutlineColor(sf::Color::Blue);
		}
		if (mouse.mouseOver(*window, buttonQuit))
		{
			//Change color of the button
			quitText.setColor(sf::Color::Red);
			buttonQuit.setOutlineColor(sf::Color::Red);

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				window->close();
		}
		else
		{
			//Change color of the button
			quitText.setColor(sf::Color::Blue);
			buttonQuit.setOutlineColor(sf::Color::Blue);
		}
		/* ---------------------------------------------- */

		//Redraw the window
		window->clear();
		window->draw(startText);
		window->draw(quitText);
		window->draw(buttonStart);
		window->draw(buttonQuit);
		window->display();
	}

	window->close();
}

Menu::~Menu() {}