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
		//D�finit le bouton correspondant au texte pr�c�dent
		sf::RectangleShape background;
		sf::Sprite buttonQuit, buttonStart, buttonScore, buttonEndLess;
		Resources res;
		//Cheat code hidded bar
		sf::RectangleShape cheatBar;
		sf::Text cheatText;
		std::string cheat;
		sf::Font arial;
		std::string scores[20];


	public:
		Menu(int width, int height, string title, Resources &res);
		~Menu();
		//Lance la f�netre de menu
		void drawScores(sf::RenderWindow*, Resources &res);
		void runWindows();
};

#endif