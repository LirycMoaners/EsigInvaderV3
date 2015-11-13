#include "..\include\Settings.h"



Settings::Settings(std::string reso, bool enemySound, bool playerSound, bool backgroundSound)
{
	this->resolution = reso;
	this->SoundBackground = backgroundSound;
	this->SoundEnemy = enemySound;
	this->SoundPlayer = playerSound;
}


Settings::~Settings()
{

}
