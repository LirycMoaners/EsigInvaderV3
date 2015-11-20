#include "..\include\Resources.h"

Resources::Resources() {

}


void Resources::loadResources()
{
	xmldata = new ConfigXml();
	img = new Img();
	cout << "Loading Music" << endl;
	cout << "Explosion music" << endl;
	explosion_snd.loadFromFile("ressources/snd/explosion.wav");
	cout << "Sound Game" << endl;
	game_music.loadFromFile("ressources/snd/sound_game.wav");
	cout << "Sound Home" << endl;
	menu_music.loadFromFile("ressources/snd/sound_home.wav");
	cout << "Sound Laser" << endl;
	laser_snd.loadFromFile("ressources/snd/laser.wav");
	cout << "Sound Missile" << endl;
	missile_snd.loadFromFile("ressources/snd/missile.wav");
	cout << "Loading Police" << endl;
	arial.loadFromFile("ressources/arial.ttf");
}
ConfigXml * Resources::getConfigXML() {
	return xmldata;
}

Img * Resources::getImg() {
	return img;
}

sf::SoundBuffer& Resources::getExplosionSnd() { return explosion_snd; }
sf::SoundBuffer& Resources::getLaserSnd() { return laser_snd; }
sf::SoundBuffer& Resources::getMissileSnd() { return missile_snd; }
sf::Font& Resources::getArialFont() { return arial; }

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
