#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Game.h"
#include "Windows.h"
#include "Resources.h"

class Menu : public Windows
{
	private:
		const int WINDOW_HEIGHT = 700; //Height of the game window
		const int WINDOW_WIDTH = 1024; //Width of the game window
		
		sf::Font arial;
		sf::Text startText, quitText;
		sf::RectangleShape buttonQuit, buttonStart;
		Resources res;
	public:
		Menu(int width, int height, string title, Resources &res);
		~Menu();
		void runWindows();
};

#endif