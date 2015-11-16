#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Game.h"
#include "Windows.h"
#include "Resources.h"

class Menu : public Windows
{
	private:
		int WINDOW_HEIGHT = 700; //Height of the game window
		int WINDOW_WIDTH = 1024; //Width of the game window

		//D�finit le bouton correspondant au texte pr�c�dent
		sf::RectangleShape background;
		sf::Sprite buttonQuit, buttonStart, buttonScore, buttonEndLess;
		sf::Sprite buttonSetting;
		Resources res;

		//Ajout des bouttons pour l'interface de settings
		int screenResolution, soundVolume, musicVolume;
		bool fullscreen;
		sf::Sprite musicVolumeButton, soundVolumeButton, resolutionButton, applyButton, cancelButton, fullscreenButton;
		sf::Text resolutionText, resolutionTitle, soundVolumeText, soundVolumeTitle, musicVolumeText, musicVolumeTitle,fullscreenText;

		//Cheat code hidded bar
		sf::RectangleShape cheatBar;
		sf::Text cheatText;
		std::string cheat;
		std::string scores[30];
		sf::Sound music;
		bool isOptionMenu;


	public:
		Menu(int width, int height, std::string title, Resources &res);
		~Menu();
		//Lance la f�netre de menu
		void drawScores(sf::RenderWindow*, Resources &res);
		void drawMainMenu();
		void runWindows();
		void switchMenus();
		void findBestScores();
		void resetCheat();
};

#endif