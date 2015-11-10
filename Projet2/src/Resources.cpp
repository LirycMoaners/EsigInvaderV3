#include "..\include\Resources.h"



Resources::Resources()
{
	xmldata = new ConfigXml();
	img = new Img();
	explosion_snd.loadFromFile("ressources/snd/explosion.wav");
}
ConfigXml * Resources::getConfigXML() {
	return xmldata;
}

Img * Resources::getImg() {
	return img;
}

sf::SoundBuffer& Resources::getExplosionSnd() { return explosion_snd; }

Resources::~Resources()
{
}
