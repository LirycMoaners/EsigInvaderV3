#include "..\include\Resources.h"



Resources::Resources()
{
	xmldata = new ConfigXml();
	img = new Img();
	explosion_snd.loadFromFile("ressources/snd/explosion.wav");
	game_music.loadFromFile("ressources/snd/sound_game.wav");
	menu_music.loadFromFile("ressources/snd/sound_home.wav");
}
ConfigXml * Resources::getConfigXML() {
	return xmldata;
}

Img * Resources::getImg() {
	return img;
}

sf::SoundBuffer& Resources::getExplosionSnd() { return explosion_snd; }

sf::SoundBuffer& Resources::getMusicSnd(int i) 
{ 
	switch (i)
	{
		case 0:
			return menu_music;
			break;
		default:
			return game_music;
			break;
	}
}

Resources::~Resources()
{
}
