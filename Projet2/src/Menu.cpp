#include "Menu.h"
#include "Mouse.h"

Menu::Menu(std::string title, Resources res) : Windows(res.getConfigXML()->getSettings()->getCurrentResolution().x, res.getConfigXML()->getSettings()->getCurrentResolution().y,res.getConfigXML()->getSettings()->isFullscreen(), title)
{
	//Setup of the window parameters
	this->res = res;
	WINDOW_WIDTH = this->res.getConfigXML()->getSettings()->getCurrentResolution().x;
	WINDOW_HEIGHT = this->res.getConfigXML()->getSettings()->getCurrentResolution().y;
	isOptionMenu = false;
	drawMainMenu();

	//Génération de la musique de fond
	music.setBuffer(this->res.getMusicSnd(0));
	music.setVolume(this->res.getConfigXML()->getSettings()->getVolumeMusic());
	music.setLoop(true);
	music.play();
}

void Menu::drawMainMenu()
{
	background.setTexture(&res.getImg()->getHome_t());
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setPosition(0, 0);

	//Main Menu buttons	
	// Définition du rectangle autour du texte
	buttonStart.setTexture(res.getImg()->getButton_t());
	buttonStart.setTextureRect(sf::IntRect(0, 0, 295, 85));
	buttonStart.setPosition(WINDOW_WIDTH / 3 - buttonStart.getGlobalBounds().width / 2, WINDOW_HEIGHT - 230);

	// Définition du rectangle autour du texte
	buttonEndLess.setTexture(res.getImg()->getButton_t());
	buttonEndLess.setTextureRect(sf::IntRect(0, 85, 295, 85));
	buttonEndLess.setPosition(WINDOW_WIDTH / 3 - buttonEndLess.getGlobalBounds().width / 2, WINDOW_HEIGHT - 130);

	// Définition du rectangle autour du texte
	buttonScore.setTexture(res.getImg()->getButton_t());
	buttonScore.setTextureRect(sf::IntRect(0, 170, 295, 85));
	buttonScore.setPosition(WINDOW_WIDTH * 2 / 3 - buttonScore.getGlobalBounds().width / 2, WINDOW_HEIGHT - 230);

	// Définition du rectangle autour du texte
	buttonQuit.setTexture(res.getImg()->getButton_t());
	buttonQuit.setTextureRect(sf::IntRect(0, 255, 295, 85));
	buttonQuit.setPosition(WINDOW_WIDTH * 2 / 3 - buttonQuit.getGlobalBounds().width / 2, WINDOW_HEIGHT - 130);

	buttonSetting.setTexture(res.getImg()->getSettingIco());
	buttonSetting.setScale(sf::Vector2f(0.8, 0.8));
	buttonSetting.setTextureRect(sf::IntRect(0, 0, 60, 60));
	buttonSetting.setPosition(WINDOW_WIDTH - buttonSetting.getGlobalBounds().width, WINDOW_HEIGHT - buttonSetting.getGlobalBounds().height);

	buttonAbout.setTexture(res.getImg()->getAbout_t());
	buttonAbout.setScale(sf::Vector2f(0.8, 0.8));
	buttonAbout.setTextureRect(sf::IntRect(0, 0, 60, 60));
	buttonAbout.setPosition(WINDOW_WIDTH - buttonSetting.getGlobalBounds().width - buttonAbout.getGlobalBounds().width, buttonSetting.getGlobalBounds().height);

	//Create the cheat bar an hide it
	cheatBar.setOutlineColor(sf::Color::Transparent);
	cheatBar.setFillColor(sf::Color::Transparent);
	cheatBar.setSize(sf::Vector2f(width - 2, 20));
	cheatBar.setOutlineThickness(1);
	cheatBar.setPosition(sf::Vector2f(1, height - 21));
	cheatText.setCharacterSize(15);
	cheatText.setFont(res.getArialFont());
	cheatText.setPosition(cheatBar.getPosition());
	cheatText.setColor(sf::Color::Transparent);
	cheatList.clear();

	//Settings buttons
	soundVolumeButton.setTexture(res.getImg()->getButtonArrow_t());
	soundVolumeButton.setScale(sf::Vector2f(0.8, 0.8));
	soundVolumeButton.setTextureRect(sf::IntRect(0, 0, 395, 85));
	soundVolumeButton.setPosition(WINDOW_WIDTH / 2 - soundVolumeButton.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - 100);

	musicVolumeButton.setTexture(res.getImg()->getButtonArrow_t());
	musicVolumeButton.setScale(sf::Vector2f(0.8, 0.8));
	musicVolumeButton.setTextureRect(sf::IntRect(0, 0, 395, 85));
	musicVolumeButton.setPosition(WINDOW_WIDTH / 2 - musicVolumeButton.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2);

	resolutionButton.setTexture(res.getImg()->getButtonArrow_t());
	resolutionButton.setScale(sf::Vector2f(0.8, 0.8));
	resolutionButton.setTextureRect(sf::IntRect(0, 0, 395, 85));
	resolutionButton.setPosition(WINDOW_WIDTH / 2 - resolutionButton.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 + 100);

	//Settings texts
	resolutionTitle.setFont(res.getArialFont());
	resolutionTitle.setCharacterSize(18);
	resolutionTitle.setString("Resolution:");
	resolutionTitle.setColor(sf::Color::Red);
	resolutionTitle.setPosition(resolutionButton.getPosition().x, resolutionButton.getPosition().y - resolutionTitle.getGlobalBounds().height - 7);
	resolutionText.setFont(res.getArialFont());
	resolutionText.setCharacterSize(25);
	resolutionText.setColor(sf::Color::White);
	resolutionText.setPosition(resolutionButton.getPosition().x + resolutionButton.getGlobalBounds().width / 2 - resolutionText.getGlobalBounds().width / 2, resolutionButton.getPosition().y + resolutionButton.getGlobalBounds().height / 2 - 8 - resolutionText.getGlobalBounds().height / 2);

	soundVolumeTitle.setFont(res.getArialFont());
	soundVolumeTitle.setCharacterSize(18);
	soundVolumeTitle.setString("Volume:");
	soundVolumeTitle.setColor(sf::Color::Red);
	soundVolumeTitle.setPosition(soundVolumeButton.getPosition().x, soundVolumeButton.getPosition().y - soundVolumeTitle.getGlobalBounds().height - 7);
	soundVolumeText.setFont(res.getArialFont());
	soundVolumeText.setCharacterSize(25);
	soundVolumeText.setColor(sf::Color::White);
	soundVolumeText.setPosition(soundVolumeButton.getPosition().x + soundVolumeButton.getGlobalBounds().width / 2 - soundVolumeText.getGlobalBounds().width / 2, soundVolumeButton.getPosition().y + soundVolumeButton.getGlobalBounds().height / 2 - 8 - soundVolumeText.getGlobalBounds().height / 2);

	musicVolumeTitle.setFont(res.getArialFont());
	musicVolumeTitle.setCharacterSize(18);
	musicVolumeTitle.setString("Musique:");
	musicVolumeTitle.setColor(sf::Color::Red);
	musicVolumeTitle.setPosition(musicVolumeButton.getPosition().x, musicVolumeButton.getPosition().y - musicVolumeTitle.getGlobalBounds().height - 7);
	musicVolumeText.setFont(res.getArialFont());
	musicVolumeText.setCharacterSize(25);
	musicVolumeText.setColor(sf::Color::White);
	musicVolumeText.setPosition(musicVolumeButton.getPosition().x + musicVolumeButton.getGlobalBounds().width / 2 - musicVolumeText.getGlobalBounds().width / 2, musicVolumeButton.getPosition().y + musicVolumeButton.getGlobalBounds().height / 2 - 8 - musicVolumeText.getGlobalBounds().height / 2);

	fullscreenText.setFont(res.getArialFont());
	fullscreenText.setCharacterSize(18);
	fullscreenText.setString("Plein écran:");
	fullscreenText.setColor(sf::Color::Red);
	fullscreenText.setPosition(resolutionButton.getPosition().x, WINDOW_HEIGHT / 2 + 200);
	fullscreenButton.setTexture(res.getImg()->getSettingIco());
	fullscreenButton.setScale(sf::Vector2f(0.6, 0.6));
	fullscreenButton.setTextureRect(sf::IntRect(120, 0, 60, 60));
	fullscreenButton.setPosition(fullscreenText.getPosition().x + fullscreenText.getGlobalBounds().width + 10, fullscreenText.getPosition().y - (fullscreenButton.getGlobalBounds().height - fullscreenText.getGlobalBounds().height - 10) / 2);

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
	string cheat = "";
	while (window->isOpen())
	{
		sf::Event event;

		//Gestion des évenements du menu principal si l'on n'est pas sur l'écran de paramètres
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
					for (int i = 0; i < 36; i++)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i))) {
							if (i >= 0 && i < 26 && cheat.size() < 100)
								cheat += 'a' + i;
							else if (i >= 26 && i < 36 && cheat.size() < 100)
								cheat += '0' + (i - 26);
							cout << "In progress :: " << cheat << endl;	
						}
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
						cheatList.push_back(cheat);
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
						Game(*window, res, false, cheatList).runGame();
						resetCheat();
						cheatList.clear();
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
						cheatList.clear();
						Game(*window, res, true, cheatList).runGame();
						cheatList.clear();
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
					{
						switchMenus();
					}
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
			window->draw(buttonSetting);
			cheatText.setString("> " + cheat);
			window->draw(cheatBar);
			window->draw(cheatText);
		}
		//Gestion des évenements du menu d'options
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

				if (mouse.mouseOver(*window, fullscreenButton))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						fullscreen = !fullscreen;
				}

				if (mouse.mouseOver(*window, applyButton))
				{
					applyButton.setTextureRect(sf::IntRect(0, 340, 395, 85));

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						//Apply settings
						Settings* settings = res.getConfigXML()->getSettings();
						settings->changeSettings(screenResolution, true, true, true, musicVolume, soundVolume, fullscreen);
						sf::Uint16 style = settings->isFullscreen() ? sf::Style::Fullscreen : sf::Style::Close;
						WINDOW_HEIGHT = settings->getCurrentResolution().y;
						WINDOW_WIDTH = settings->getCurrentResolution().x;
						window->create(sf::VideoMode(settings->getCurrentResolution().x, settings->getCurrentResolution().y), title, style);
						window->setFramerateLimit(60);
						music.setVolume(settings->getVolumeMusic());
						//Save settings into XML File
						res.getConfigXML()->setSetting(settings);
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
			fullscreenButton.setTextureRect(sf::IntRect(fullscreen ? 180 : 120, 0, 60, 60));

			//Redraw the window
			window->clear();
			window->draw(background);
			window->draw(musicVolumeButton);
			window->draw(soundVolumeButton);
			window->draw(resolutionButton);
			window->draw(fullscreenButton);
			window->draw(cancelButton);
			window->draw(applyButton);
			window->draw(soundVolumeText);
			window->draw(musicVolumeText);
			window->draw(resolutionText);
			window->draw(fullscreenText);
			window->draw(resolutionTitle);
			window->draw(musicVolumeTitle);
			window->draw(soundVolumeTitle);
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
		fullscreen = res.getConfigXML()->getSettings()->isFullscreen();
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
	background.setTextureRect(sf::IntRect(0, 0, this->window->getSize().x < 8192 ? this->window->getSize().x : 8192, this->window->getSize().y < 768 ? this->window->getSize().y : 768));
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setPosition(0, 0);
	window->draw(background);

	//Draw best scores
	sf::Text Title;
	sf::Text scoresText[10];
	const int stringLength = 83;

	//Get scores from XMLFile
	findBestScores(); // <-- A définir

	Title.setFont(res.getArialFont());
	Title.setCharacterSize(50);
	Title.setString("High Scores");
	Title.setPosition((window->getSize().x - Title.getGlobalBounds().width) / 2, 100);
	window->draw(Title);

	for (int i = 0; i < sizeof(scoresText) / sizeof(scoresText[0]); i++)
	{
		scoresText[i].setFont(res.getArialFont());
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
			scoresText[i].setString(scores[3 * i] + " " + tab + " " + scores[3 * i + 1] + " ................. " + scores[3 * i + 2]);
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