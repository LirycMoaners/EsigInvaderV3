#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEM 3

#include "Global.h"
class MainMenu
{
public:
	
	int isMenuSelected = false;
	MainMenu();
	MainMenu(int width, int height);
	void drawMenu(sf::RenderWindow*);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }
	~MainMenu();
private:
	int selectedItemIndex;
	sf::Text menu[MAX_NUMBER_OF_ITEM];
	sf::Font font;
	
};

