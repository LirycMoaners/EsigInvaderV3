#pragma once
#include <iostream>
#include <list>
#include "Game.h"
#include "Windows.h"
#include "Resources.h"

class Menu : public Windows
{
	private:
		int WINDOW_HEIGHT; //Height of the game window
		int WINDOW_WIDTH; //Width of the game window

		//Définit le bouton correspondant au texte précédent
		sf::RectangleShape background;
		sf::Sprite buttonQuit, buttonStart, buttonScore, buttonEndLess;
		sf::Sprite buttonSetting, buttonAbout;
		Resources res;

		//Ajout des bouttons pour l'interface de settings
		int screenResolution, soundVolume, musicVolume;
		bool fullscreen;
		sf::Sprite musicVolumeButton, soundVolumeButton, resolutionButton, applyButton, cancelButton, fullscreenButton;
		sf::Text resolutionText, resolutionTitle, soundVolumeText, soundVolumeTitle, musicVolumeText, musicVolumeTitle,fullscreenText;

		//Cheat code hidded bar
		sf::RectangleShape cheatBar;
		sf::Text cheatText;
		std::list<std::string> cheatList;
		std::string scores[30];
		sf::Sound music;
		bool isOptionMenu;


	public:
		Menu(std::string title, Resources res);
		~Menu();
		//Lance la fênetre de menu
		void drawScores(sf::RenderWindow*, Resources &res);
		void drawMainMenu();
		void runWindows();
		void switchMenus();
		void findBestScores();
		void resetCheat();
};