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
	buttonStart.setPosition(WINDOW_WIDTH / 2 - buttonStart.getGlobalBounds().width / 2, 270);

	// Définition du rectangle autour du texte
	buttonEndLess.setTexture(res.getImg()->getButton_t());
	buttonEndLess.setTextureRect(sf::IntRect(0, 85, 295, 85));
	buttonEndLess.setPosition(WINDOW_WIDTH / 2 - buttonEndLess.getGlobalBounds().width / 2, 370);

	// Définition du rectangle autour du texte
	buttonScore.setTexture(res.getImg()->getButton_t());
	buttonScore.setTextureRect(sf::IntRect(0, 170, 295, 85));
	buttonScore.setPosition(WINDOW_WIDTH / 2 - buttonScore.getGlobalBounds().width / 2, 470);

	// Définition du rectangle autour du texte
	buttonQuit.setTexture(res.getImg()->getButton_t());
	buttonQuit.setTextureRect(sf::IntRect(0, 255, 295, 85));
	buttonQuit.setPosition(WINDOW_WIDTH / 2 - buttonQuit.getGlobalBounds().width / 2, 570);

	//Create the cheat bar an hide it
	cheatBar.setOutlineColor(sf::Color::Transparent);
	cheatBar.setFillColor(sf::Color::Transparent);
	cheatBar.setSize(sf::Vector2f(width-2, 20));
	cheatBar.setOutlineThickness(1);
	cheatBar.setPosition(sf::Vector2f(1,height-21));
	arial.loadFromFile("ressources/arial.ttf");
	cheatText.setCharacterSize(15);
	cheatText.setFont(arial);
	cheatText.setPosition(cheatBar.getPosition());
	cheatText.setColor(sf::Color::Transparent);
	cheatString = "> ";
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
		
			//Cheat bar control
			if (event.type == sf::Event::KeyPressed)
			{
				for (int i = 0; i < 26; i++)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i)))
						cheatString += ('a' + i);	//Add the character to the player name
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && cheatString.size() > 2)
					cheatString.resize(cheatString.size() - 1); //Remove the last letter
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
				{
					//Check if the cheatBar is currently displayed or not
					if (cheatBar.getFillColor() == sf::Color::Transparent)
					{
						cheatBar.setFillColor(sf::Color::Black);
						cheatBar.setOutlineColor(sf::Color::Green);
						cheatText.setColor(sf::Color::White);
						cheatString = "> ";
					}
					else
					{
						cheatBar.setFillColor(sf::Color::Transparent);
						cheatBar.setOutlineColor(sf::Color::Transparent);
						cheatText.setColor(sf::Color::Transparent);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					cheatBar.setFillColor(sf::Color::Transparent);
					cheatBar.setOutlineColor(sf::Color::Transparent);
					cheatText.setColor(sf::Color::Transparent);

					//Set instruction to execute after the player press enter on the console tab
					std::string cheat = cheatString.substr(2, cheatString.size());
					std::cout << "Cheat entered: " << cheat << std::endl;

				}
			}
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

		if (mouse.mouseOver(*window, buttonEndLess))
		{
			//Change color of the button
			buttonEndLess.setTextureRect(sf::IntRect(0, 255, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				Game(*window, res).runGame();
		}
		else
		{
			//Change color of the button
			buttonEndLess.setTextureRect(sf::IntRect(0, 85, 295, 85));
		}
		if (mouse.mouseOver(*window, buttonScore))
		{
			//Change color of the button
			buttonScore.setTextureRect(sf::IntRect(0, 255, 295, 85));

			//Button clicked
			//TODO
		}
		else
		{
			//Change color of the button
			buttonScore.setTextureRect(sf::IntRect(0, 85, 295, 85));
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
		window->draw(buttonEndLess);
		window->draw(buttonScore);
		window->draw(buttonQuit);
		cheatText.setString(cheatString);
		window->draw(cheatBar);
		window->draw(cheatText);
		window->display();
	}

	window->close();
}

Menu::~Menu() {}