#include "Menu.h"
#include "Mouse.h"

Menu::Menu(int width, int height, std::string title, Resources &res) : Windows(width, height, title)
{
	//Cr�ation du menu de param�tres
	isOptionMenu = false;
	drawMainMenu();

	//G�n�ration de la musique de fond
	music.setBuffer(res.getMusicSnd(0));
	music.setLoop(true);
	music.play();
}

void Menu::drawMainMenu()
{
	background.setTexture(&res.getImg()->getHome_t());
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setPosition(0, 0);

	//Main Menu buttons	
	// D�finition du rectangle autour du texte
	buttonStart.setTexture(res.getImg()->getButton_t());
	buttonStart.setTextureRect(sf::IntRect(0, 0, 295, 85));
	buttonStart.setPosition(WINDOW_WIDTH / 3 - buttonStart.getGlobalBounds().width / 2, 470);

	// D�finition du rectangle autour du texte
	buttonEndLess.setTexture(res.getImg()->getButton_t());
	buttonEndLess.setTextureRect(sf::IntRect(0, 85, 295, 85));
	buttonEndLess.setPosition(WINDOW_WIDTH / 3 - buttonEndLess.getGlobalBounds().width / 2, 570);

	// D�finition du rectangle autour du texte
	buttonScore.setTexture(res.getImg()->getButton_t());
	buttonScore.setTextureRect(sf::IntRect(0, 170, 295, 85));
	buttonScore.setPosition(WINDOW_WIDTH * 2 / 3 - buttonScore.getGlobalBounds().width / 2, 470);

	// D�finition du rectangle autour du texte
	buttonQuit.setTexture(res.getImg()->getButton_t());
	buttonQuit.setTextureRect(sf::IntRect(0, 255, 295, 85));
	buttonQuit.setPosition(WINDOW_WIDTH * 2 / 3 - buttonQuit.getGlobalBounds().width / 2, 570);

	buttonSetting.setTexture(res.getImg()->getSettingIco());
	buttonSetting.setScale(sf::Vector2f(0.8, 0.8));
	buttonSetting.setTextureRect(sf::IntRect(0, 0, 60, 60));
	buttonSetting.setPosition(WINDOW_WIDTH - buttonSetting.getGlobalBounds().width, WINDOW_HEIGHT - buttonSetting.getGlobalBounds().height);

	//Create the cheat bar an hide it
	cheatBar.setOutlineColor(sf::Color::Transparent);
	cheatBar.setFillColor(sf::Color::Transparent);
	cheatBar.setSize(sf::Vector2f(width - 2, 20));
	cheatBar.setOutlineThickness(1);
	cheatBar.setPosition(sf::Vector2f(1, height - 21));
	arial.loadFromFile("ressources/arial.ttf");
	cheatText.setCharacterSize(15);
	cheatText.setFont(arial);
	cheatText.setPosition(cheatBar.getPosition());
	cheatText.setColor(sf::Color::Transparent);
	cheat = "";

	//Settings buttons
	soundVolumeButton.setTexture(res.getImg()->getButtonArrow_t());
	soundVolumeButton.setScale(sf::Vector2f(0.8, 0.8));
	soundVolumeButton.setTextureRect(sf::IntRect(0, 0, 395, 85));
	soundVolumeButton.setPosition(WINDOW_WIDTH / 2 - soundVolumeButton.getGlobalBounds().width / 2, 250);

	musicVolumeButton.setTexture(res.getImg()->getButtonArrow_t());
	musicVolumeButton.setScale(sf::Vector2f(0.8, 0.8));
	musicVolumeButton.setTextureRect(sf::IntRect(0, 0, 395, 85));
	musicVolumeButton.setPosition(WINDOW_WIDTH / 2 - musicVolumeButton.getGlobalBounds().width / 2, 350);

	resolutionButton.setTexture(res.getImg()->getButtonArrow_t());
	resolutionButton.setScale(sf::Vector2f(0.8, 0.8));
	resolutionButton.setTextureRect(sf::IntRect(0, 0, 395, 85));
	resolutionButton.setPosition(WINDOW_WIDTH / 2 - resolutionButton.getGlobalBounds().width / 2, 450);

	//Settings texts
	resolutionTitle.setFont(arial);
	resolutionTitle.setCharacterSize(18);
	resolutionTitle.setString("Resolution:");
	resolutionTitle.setColor(sf::Color::Red);
	resolutionTitle.setPosition(resolutionButton.getPosition().x, resolutionButton.getPosition().y - resolutionTitle.getGlobalBounds().height - 7);
	resolutionText.setFont(arial);
	resolutionText.setCharacterSize(25);
	resolutionText.setColor(sf::Color::White);
	resolutionText.setPosition(resolutionButton.getPosition().x + resolutionButton.getGlobalBounds().width / 2 - resolutionText.getGlobalBounds().width / 2, resolutionButton.getPosition().y + resolutionButton.getGlobalBounds().height / 2 - 8 - resolutionText.getGlobalBounds().height / 2);

	soundVolumeTitle.setFont(arial);
	soundVolumeTitle.setCharacterSize(18);
	soundVolumeTitle.setString("Volume:");
	soundVolumeTitle.setColor(sf::Color::Red);
	soundVolumeTitle.setPosition(soundVolumeButton.getPosition().x, soundVolumeButton.getPosition().y - soundVolumeTitle.getGlobalBounds().height - 7);
	soundVolumeText.setFont(arial);
	soundVolumeText.setCharacterSize(25);
	soundVolumeText.setColor(sf::Color::White);
	soundVolumeText.setPosition(soundVolumeButton.getPosition().x + soundVolumeButton.getGlobalBounds().width / 2 - soundVolumeText.getGlobalBounds().width / 2, soundVolumeButton.getPosition().y + soundVolumeButton.getGlobalBounds().height / 2 - 8 - soundVolumeText.getGlobalBounds().height / 2);

	musicVolumeTitle.setFont(arial);
	musicVolumeTitle.setCharacterSize(18);
	musicVolumeTitle.setString("Musique:");
	musicVolumeTitle.setColor(sf::Color::Red);
	musicVolumeTitle.setPosition(musicVolumeButton.getPosition().x, musicVolumeButton.getPosition().y - musicVolumeTitle.getGlobalBounds().height - 7);
	musicVolumeText.setFont(arial);
	musicVolumeText.setCharacterSize(25);
	musicVolumeText.setColor(sf::Color::White);
	musicVolumeText.setPosition(musicVolumeButton.getPosition().x + musicVolumeButton.getGlobalBounds().width / 2 - musicVolumeText.getGlobalBounds().width / 2, musicVolumeButton.getPosition().y + musicVolumeButton.getGlobalBounds().height / 2 - 8 - musicVolumeText.getGlobalBounds().height / 2);

	fullscreenText.setFont(arial);
	fullscreenText.setCharacterSize(18);
	fullscreenText.setString("Plein �cran:");
	fullscreenText.setColor(sf::Color::Red);
	fullscreenText.setPosition(resolutionButton.getPosition().x, 550);
	fullscreenButton.setTexture(res.getImg()->getSettingIco());
	fullscreenButton.setScale(sf::Vector2f(0.6, 0.6));
	fullscreenButton.setTextureRect(sf::IntRect(120, 0, 60, 60));
	fullscreenButton.setPosition(fullscreenText.getPosition().x + fullscreenText.getGlobalBounds().width, fullscreenText.getPosition().y - fullscreenButton.getGlobalBounds().height / 2);

	cancelButton.setTexture(res.getImg()->getButtonArrow_t());
	cancelButton.setScale(sf::Vector2f(0.6, 0.6));
	cancelButton.setTextureRect(sf::IntRect(0, 425, 395, 85));
	cancelButton.setPosition(WINDOW_WIDTH - cancelButton.getGlobalBounds().width + 20, WINDOW_HEIGHT - cancelButton.getGlobalBounds().height);
	applyButton.setTexture(res.getImg()->getButtonArrow_t());
	applyButton.setScale(sf::Vector2f(0.6, 0.6));
	applyButton.setTextureRect(sf::IntRect(0, 255, 395, 85));
	applyButton.setPosition(cancelButton.getPosition().x - applyButton.getGlobalBounds().width + 60, WINDOW_HEIGHT - applyButton.getGlobalBounds().height);
}

void Menu::runWindows()
{
	Mouse mouse;

	while (window->isOpen())
	{
		sf::Event event;

		//Gestion des �venements du menu principal si l'on n'est pas sur l'�cran de param�tres
		if (!isOptionMenu)
		{
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
						drawScores(window, res);
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

				if (mouse.mouseOver(*window, buttonSetting))
				{
					//Change color of the button
					buttonSetting.setTextureRect(sf::IntRect(60, 0, 60, 60));

					//Button clicked
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						switchMenus();
				}
				else
					buttonSetting.setTextureRect(sf::IntRect(0, 0, 60, 60));
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
			window->draw(buttonSetting);
		}
		//Gestion des �venements du menu d'options
		else
		{
			//Mouse event and menu animations
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();

				/* Change style of buttons */
				int val = mouse.mouseOver(*window, musicVolumeButton, 50);
				musicVolumeButton.setTextureRect(sf::IntRect(0, val * 85, 395, 85));

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && val == 1)
				{
					if (musicVolume < 100)
						musicVolume += 1;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && val == 2)
				{
					if (musicVolume > 0)
						musicVolume -= 1;
				}
				
				/* Change style of buttons */
				val = mouse.mouseOver(*window, soundVolumeButton, 50);
				soundVolumeButton.setTextureRect(sf::IntRect(0, val * 85, 395, 85));

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && val == 1)
				{
					if (soundVolume < 100)
						soundVolume += 1;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && val == 2)
				{
					if (soundVolume > 0)
						soundVolume -= 1;
				}
				
				/* Change style of buttons */
				val = mouse.mouseOver(*window, resolutionButton, 50);
				resolutionButton.setTextureRect(sf::IntRect(0, val * 85, 395, 85));

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && val == 1)
				{
					if (screenResolution < res.getConfigXML()->getSettings()->getResolutions().size() - 1)
						screenResolution += 1;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && val == 2)
				{
					if (screenResolution > 0)
						screenResolution -= 1;
				}

				if (mouse.mouseOver(*window, applyButton))
				{
					applyButton.setTextureRect(sf::IntRect(0, 340, 395, 85));

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						//Apply settings
						Settings* settings = res.getConfigXML()->getSettings();
						settings->changeSettings(screenResolution,true,true,true,musicVolume,soundVolume);
						sf::Uint32 style = settings->isFullscreen() ? sf::Style::Fullscreen : sf::Style::Close;
						WINDOW_HEIGHT = settings->getCurrentResolution().y;
						WINDOW_WIDTH = settings->getCurrentResolution().x;
						window->create(sf::VideoMode(settings->getCurrentResolution().x, settings->getCurrentResolution().y), title, style);
						window->setFramerateLimit(60);
						drawMainMenu();
						switchMenus();
					}
				}
				else
					applyButton.setTextureRect(sf::IntRect(0, 255, 395, 85));

				if (mouse.mouseOver(*window, cancelButton))
				{
					cancelButton.setTextureRect(sf::IntRect(0, 510, 395, 85));

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						switchMenus();
				}
				else
					cancelButton.setTextureRect(sf::IntRect(0, 425, 395, 85));
			}
			//Get setting informations
			musicVolumeText.setString(std::to_string(musicVolume) + " %");
			musicVolumeText.setPosition(musicVolumeButton.getPosition().x + musicVolumeButton.getGlobalBounds().width / 2 - musicVolumeText.getGlobalBounds().width / 2, musicVolumeButton.getPosition().y + musicVolumeButton.getGlobalBounds().height / 2 - 8 - musicVolumeText.getGlobalBounds().height / 2);
			soundVolumeText.setString(std::to_string(soundVolume) + " %");
			soundVolumeText.setPosition(soundVolumeButton.getPosition().x + soundVolumeButton.getGlobalBounds().width / 2 - soundVolumeText.getGlobalBounds().width / 2, soundVolumeButton.getPosition().y + soundVolumeButton.getGlobalBounds().height / 2 - 8 - soundVolumeText.getGlobalBounds().height / 2);
			resolutionText.setString(std::to_string(res.getConfigXML()->getSettings()->getResolutions().at(screenResolution).x) + " x " + std::to_string(res.getConfigXML()->getSettings()->getResolutions().at(screenResolution).y));
			resolutionText.setPosition(resolutionButton.getPosition().x + resolutionButton.getGlobalBounds().width / 2 - resolutionText.getGlobalBounds().width / 2, resolutionButton.getPosition().y + resolutionButton.getGlobalBounds().height / 2 - 8 - resolutionText.getGlobalBounds().height / 2);

			//Redraw the window
			window->clear();
			window->draw(background);
			window->draw(musicVolumeButton);
			window->draw(soundVolumeButton);
			window->draw(resolutionButton);
			window->draw(resolutionText);
			window->draw(resolutionTitle);
			window->draw(soundVolumeText);
			window->draw(soundVolumeTitle);
			window->draw(musicVolumeText);
			window->draw(musicVolumeTitle);
			window->draw(cancelButton);
			window->draw(applyButton);
			window->draw(fullscreenButton);
			window->draw(fullscreenText);
		}

		window->display();
	}

	window->close();
}

void Menu::switchMenus()
{
	if (isOptionMenu)
		isOptionMenu = false;
	else
	{
		isOptionMenu = true;

		//Get setting values
		soundVolume = res.getConfigXML()->getSettings()->getVolumeSound();
		musicVolume = res.getConfigXML()->getSettings()->getVolumeMusic();
		screenResolution = res.getConfigXML()->getSettings()->getResolutionInt();
	}
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
	findBestScores(); // <-- A d�finir

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
			std::string tab;
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