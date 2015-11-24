#include "..\include\GameHub.h"

GameHub::GameHub(Resources &res, int width)
{
	//Create healthbar
	healthText.setFont(res.getArialFont());
	healthText.setCharacterSize(HUB_HEIGHT - 2);
	healthText.setString("Health:");
	healthText.setColor(outlineColor);
	healthText.setPosition(2, 0);
	healthBarOutline.setFillColor(sf::Color::Transparent);
	healthBarOutline.setOutlineThickness(2);
	healthBarOutline.setOutlineColor(outlineColor);
	healthBarOutline.setPosition(healthText.getPosition().x + healthText.getLocalBounds().width + 4, 4);
	healthBarOutline.setSize(sf::Vector2f(204, HUB_HEIGHT - 4));
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(healthBarOutline.getPosition());
	healthBar.setSize(sf::Vector2f(204, HUB_HEIGHT - 4));

	//Draw score text
	scoreText.setFont(res.getArialFont());
	scoreText.setCharacterSize(HUB_HEIGHT - 2);
	scoreText.setString("0");
	scoreText.setColor(outlineColor);

	//Draw the boss health bar
	bossHealthBarOutline.setFillColor(sf::Color::Transparent);
	bossHealthBarOutline.setOutlineThickness(2);
	bossHealthBarOutline.setOutlineColor(outlineColor);
	bossHealthBarOutline.setSize(sf::Vector2f(204, HUB_HEIGHT - 4));
	bossHealthBarOutline.setPosition(width - bossHealthBarOutline.getGlobalBounds().width - 4, 4);
	bossHealthBar.setFillColor(sf::Color::Green);
	bossHealthBar.setPosition(bossHealthBarOutline.getPosition());
	bossHealthBar.setSize(sf::Vector2f(204, HUB_HEIGHT - 4));
	bossHealthText.setFont(res.getArialFont());
	bossHealthText.setCharacterSize(HUB_HEIGHT - 2);
	bossHealthText.setString("BOSS:");
	bossHealthText.setColor(outlineColor);
	bossHealthText.setPosition(bossHealthBarOutline.getPosition().x - bossHealthText.getGlobalBounds().width - 5, 0);

	//Hide the boss bar
	resetHub();
}

GameHub::~GameHub() {}

void GameHub::resetHub()
{
	//Toggle visibility of the boss health bar
	bossHealthBarOutline.setOutlineColor(sf::Color::Transparent);
	bossHealthBar.setScale(sf::Vector2f(0, 0));
	bossHealthText.setColor(sf::Color::Transparent);
}

void GameHub::updateHub(sf::RenderWindow* window, Spaceship* spaceObject, Boss* boss, int score)
{
	//Update bar size
	float healthScale = spaceObject->getHealth() > 0 ? ((float)spaceObject->getHealth() / spaceObject->getHealthMax()) : 0;
	healthBar.setScale(sf::Vector2f(healthScale, 1));
	healthBar.setFillColor(sf::Color((255 - healthScale * 255), healthScale * 255, 0));

	//Display boss health bar if boss spawned
	if (boss != NULL)
	{
		if (bossHealthText.getColor() == sf::Color::Transparent)
		{
			//Toggle visibility of the boss health bar
			bossHealthBarOutline.setOutlineColor(outlineColor);
			bossHealthBar.setScale(sf::Vector2f(1, 1));
			bossHealthText.setColor(outlineColor);
		}
		float bossHealthScale = spaceObject->getHealth() > 0 ? ((float)spaceObject->getHealth() / spaceObject->getHealthMax()) : 0;
		bossHealthBar.setScale(sf::Vector2f(bossHealthScale, 1));
		bossHealthBar.setFillColor(sf::Color((255 - bossHealthScale * 255), bossHealthScale * 255, 0));
	}

	//Draw score
	scoreText.setString("Score: "+std::to_string(score));
	scoreText.setPosition(window->getSize().x / 2  - scoreText.getGlobalBounds().width / 2, 0);

	//Draw component in the windows
	window->draw(healthText);
	window->draw(scoreText);
	window->draw(healthBarOutline);
	window->draw(healthBar);
	window->draw(bossHealthText);
	window->draw(bossHealthBarOutline);
	window->draw(bossHealthBar);
}

void GameHub::setPlayerPseudo(sf::RenderWindow* window, int score, Control* c, Resources &res)
{
	while (!c->quit() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		//Clear the window
		window->clear();

		//Background texture
		sf::RectangleShape background;
		background.setTexture(&res.getImg()->getBackground_t());
		background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
		background.setTextureRect(sf::IntRect(0, 0, window->getSize().x < 8192 ? window->getSize().x : 8192, window->getSize().y < 768 ? window->getSize().y : 768));
		background.setPosition(0, 0);
		window->draw(background);

		//Draw window title & player pseudo
		sf::Text title, pseudoTxt;

		title.setFont(res.getArialFont());
		title.setCharacterSize(50);
		title.setString("Your score is " + std::to_string(score) + "!\n Player Name:");
		title.setPosition((window->getSize().x - title.getGlobalBounds().width) / 2, window->getSize().y / 2);
		window->draw(title);

		//Keyboard control to add characters to the player name
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			if (event.type == sf::Event::KeyPressed)
			{

				for (int i = 0; i < 26; i++)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i)) && playerPseudo.size() < 7)
						playerPseudo += ('A' + i);	//Add the character to the player name
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && playerPseudo.size() > 0)
					playerPseudo.resize(playerPseudo.size() - 1); //Remove the last letter
			}
		}

		//Display the player name
		pseudoTxt.setFont(res.getArialFont());
		pseudoTxt.setCharacterSize(40);
		pseudoTxt.setString(playerPseudo);
		pseudoTxt.setPosition((window->getSize().x - pseudoTxt.getGlobalBounds().width) / 2, window->getSize().y / 2 + 120);
		window->draw(pseudoTxt);

		//Show windows graphical components
		window->display();

		c->runHub();
	}
}

std::string GameHub::getPlayerPseudo() {
	return playerPseudo;
}