#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

class Settings
{
	public:
		Settings(int reso, bool enemySound,bool playerSound, bool backgroundSound, int volumeMusic, int volumeSound, bool fullscreen);
		~Settings();

		bool getSoundEnemy();
		bool getSoundPlayer();
		bool getSoundBackground();
		bool isFullscreen();
		int getVolumeMusic();
		int getVolumeSound();

		sf::Vector2u getCurrentResolution();
		std::vector<sf::Vector2u> &getResolutions();
		int getResolutionInt();
		void changeSettings(int reso, bool enemySound, bool playerSound, bool backgroundSound, int volumeMusic, int volumeSound, bool fullscreen);

	private : 
		int resolution;
		std::vector<sf::Vector2u> resolutions;
		bool SoundEnemy = true;
		bool SoundPlayer = true;
		bool SoundBackground = true;
		bool fullscreen = false;
		int volumeMusic;
		int volumeSound;
};

