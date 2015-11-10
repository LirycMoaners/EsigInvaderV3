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
	sf::SoundBuffer& getExplosionSnd();
	Img * getImg();

	private : 
		ConfigXml * xmldata;
		Img * img;
		sf::SoundBuffer explosion_snd;
};

