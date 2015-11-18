#pragma once
#include "ConfigXml.h"
#include "SFML/Audio.hpp"
#include "Img.h"

class Resources
{
	public:
		Resources();
		~Resources();

		ConfigXml * getConfigXML();
		void loadResources();
		sf::SoundBuffer& getExplosionSnd();
		sf::SoundBuffer& getMusicSnd(int);
		sf::SoundBuffer& getLaserSnd();
		sf::SoundBuffer& getMissileSnd();
		sf::Font& getArialFont();
		Img * getImg();

		private : 
			ConfigXml * xmldata;
			Img * img;
			sf::Font arial;
			sf::SoundBuffer explosion_snd;
			sf::SoundBuffer laser_snd, missile_snd;
			sf::SoundBuffer menu_music, game_music;
};

