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
	buttonStart.setPosition(WINDOW_WIDTH / 3 - buttonStart.getGlobalBounds().width / 2, 470);

	// Définition du rectangle autour du texte
	buttonEndLess.setTexture(res.getImg()->getButton_t());
	buttonEndLess.setTextureRect(sf::IntRect(0, 85, 295, 85));
	buttonEndLess.setPosition(WINDOW_WIDTH / 3 - buttonEndLess.getGlobalBounds().width / 2, 570);

	// Définition du rectangle autour du texte
	buttonScore.setTexture(res.getImg()->getButton_t());
	buttonScore.setTextureRect(sf::IntRect(0, 170, 295, 85));
	buttonScore.setPosition(WINDOW_WIDTH * 2 / 3 - buttonScore.getGlobalBounds().width / 2, 470);

	// Définition du rectangle autour du texte
	buttonQuit.setTexture(res.getImg()->getButton_t());
	buttonQuit.setTextureRect(sf::IntRect(0, 255, 295, 85));
	buttonQuit.setPosition(WINDOW_WIDTH * 2 / 3 - buttonQuit.getGlobalBounds().width / 2, 570);

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
	cheat = "";

	//Génération de la musique de fond
	music.setBuffer(res.getMusicSnd(0));
	music.setLoop(true);
	music.play();
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
						cheat += ('a' + i);	//Add the character to the player name
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && cheat.size() > 0)
					cheat.resize(cheat.size() - 1); //Remove the last letter
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
				{
					//Check if the cheatBar is currently displayed or not
					if (cheatBar.getFillColor() == sf::Color::Transparent)
					{
						cheatBar.setFillColor(sf::Color::Black);
						cheatBar.setOutlineColor(sf::Color::Green);
						cheatText.setColor(sf::Color::White);
						cheat.clear();
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
					std::cout << "Cheat entered: " << cheat << std::endl;
				}
			}
		}

		/* Change style of buttons */
		if (mouse.mouseOver(*window, buttonStart))
		{
			//Change color of the button
			buttonStart.setTextureRect(sf::IntRect(0, 340, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				music.stop();
				Game(*window, res, false, cheat).runGame();
				resetCheat();
				cheat = "";
				music.play();
			}
		}
		else
		{
			//Change color of the button
			buttonStart.setTextureRect(sf::IntRect(0, 0, 295, 85));
		}

		if (mouse.mouseOver(*window, buttonEndLess))
		{
			//Change color of the button
			buttonEndLess.setTextureRect(sf::IntRect(0, 425, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				music.stop();
				Game(*window, res, true, "").runGame();
				cheat = "";
				resetCheat();
				music.play();
			}
		}
		else
		{
			//Change color of the button
			buttonEndLess.setTextureRect(sf::IntRect(0, 85, 295, 85));
		}
		if (mouse.mouseOver(*window, buttonScore))
		{
			//Change color of the button
			buttonScore.setTextureRect(sf::IntRect(0, 510, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				drawScores(window,res);
		}
		else
		{
			//Change color of the button
			buttonScore.setTextureRect(sf::IntRect(0, 170, 295, 85));
		}



		if (mouse.mouseOver(*window, buttonQuit))
		{
			//Change color of the button
			buttonQuit.setTextureRect(sf::IntRect(0, 595, 295, 85));

			//Button clicked
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				window->close();
		}
		else
		{
			//Change color of the button
			buttonQuit.setTextureRect(sf::IntRect(0, 255, 295, 85));
		}
		/* ---------------------------------------------- */

		//Redraw the window
		window->clear();
		window->draw(background);
		window->draw(buttonStart);
		window->draw(buttonEndLess);
		window->draw(buttonScore);
		window->draw(buttonQuit);
		cheatText.setString("> " + cheat);
		window->draw(cheatBar);
		window->draw(cheatText);
		window->display();
	}

	window->close();
}

void Menu::drawScores(sf::RenderWindow* window, Resources &res)
{
	//Clear the current window content
	window->clear();

	//Background texture
	sf::RectangleShape background;
	background.setTexture(&res.getImg()->getBackground_t());
	background.setTextureRect(sf::IntRect(0, 0, window->getSize().x, window->getSize().y));
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setPosition(0, 0);
	window->draw(background);

	//Draw best scores
	sf::Text Title;
	sf::Text scoresText[10];
	const int stringLength = 83;

	//Get scores from XMLFile
	findBestScores(); // <-- A définir

	Title.setFont(arial);
	Title.setCharacterSize(50);
	Title.setString("High Scores");
	Title.setPosition((window->getSize().x - Title.getGlobalBounds().width) / 2, 100);
	window->draw(Title);

	for (int i = 0; i < sizeof(scoresText) / sizeof(scoresText[0]); i++)
	{
		scoresText[i].setFont(arial);
		scoresText[i].setCharacterSize(20);

		//Set score values
		if (scores[3 * i] != "")
		{
			//Create tabulation
			string tab;
			int k = 0;
			while (scores[3 * i].size() + scores[3 * i + 1].size() + scores[3 * i + 2].size() + k < (stringLength - 22))
			{
				tab += '.';
				k++;
			}				
			scoresText[i].setString(scores[3 * i] + " "+ tab +" "+ scores[3 * i + 1] + " ................. " + scores[3 * i + 2]);
		}			
		else
			scoresText[i].setString("UNKNOWN ............................................. 000000 ................. N/A");
		scoresText[i].setPosition((WINDOW_WIDTH - scoresText[i].getGlobalBounds().width) / 2, 200 + i * (WINDOW_HEIGHT / 15));
		window->draw(scoresText[i]);
	}

	//Show windows graphical components
	window->display();

	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}

void Menu::findBestScores() {

	tinyxml2::XMLDocument scoreDoc;
	tinyxml2::XMLError error = scoreDoc.LoadFile("conf/data.db");
	int compteur = 0;

	if (error == tinyxml2::XML_SUCCESS) 
	{
		tinyxml2::XMLElement * elemt;
		tinyxml2::XMLElement * node = scoreDoc.RootElement();
		elemt = node->FirstChildElement("Score");
		do 
		{
			if (elemt != NULL) 
			{
				scores[3 * compteur + 0] = elemt->Attribute("user");
				scores[3 * compteur + 1] = elemt->Attribute("value");
				scores[3 * compteur + 2] = elemt->Attribute("mode");
				elemt = elemt->NextSiblingElement("Score");
				compteur += 1;
			}
		} while (compteur != 10 && elemt != NULL);
	}
}

void Menu::resetCheat()
{
	res.getImg()->setSpaceship_t("ressources/spaceship.png");
	res.getImg()->setEnemy_t("ressources/enemy.png");
}

Menu::~Menu() {}