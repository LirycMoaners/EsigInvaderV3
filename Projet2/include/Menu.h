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
		//La police du texte
		sf::Font arial;
		//D�finit le texte affich� sur l'�cran en fonction du contexte quitter ou commencer
		sf::Text startText, quitText;
		//D�finit le bouton correspondant au texte pr�c�dent
		sf::RectangleShape buttonQuit, buttonStart;
		Resources res;
	public:
		Menu(int width, int height, string title, Resources &res);
		~Menu();
		//Lance la f�netre de menu
		void runWindows();
};

#endif