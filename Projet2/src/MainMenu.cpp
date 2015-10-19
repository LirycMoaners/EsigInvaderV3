#include "..\include\MainMenu.h"

MainMenu::MainMenu() {

}
MainMenu::MainMenu(int width, int height)
{
	if (!font.loadFromFile("ressources/arial.ttf"))
	{
		std::cout << "oups pas font!" << std::endl;
	}
	menu[0].setString("Play");
	menu[0].setColor(sf::Color::Red);
	menu[0].setFont(font);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 1));

	menu[1].setString("Options");
	menu[1].setColor(sf::Color::White);
	menu[1].setFont(font);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 2));

	menu[2].setString("Exit");
	menu[2].setColor(sf::Color::White);
	menu[2].setFont(font);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEM + 1) * 3));

	selectedItemIndex = 0;
}

void MainMenu::drawMenu(sf::RenderWindow *windows)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++)
		windows->draw(menu[i]);
}

void MainMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void MainMenu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

MainMenu::~MainMenu()
{
}
