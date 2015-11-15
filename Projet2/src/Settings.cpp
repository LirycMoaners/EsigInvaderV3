#include "..\include\Settings.h"

using namespace std;

Settings::Settings(int reso, bool enemySound, bool playerSound, bool backgroundSound, int volumeMusic, int volumeSound)
{
	this->resolution = reso;
	this->SoundBackground = backgroundSound;
	this->SoundEnemy = enemySound;
	this->SoundPlayer = playerSound;
	this->volumeSound = volumeSound;
	this->volumeMusic = volumeMusic;
}

Settings::~Settings()
{

}

sf::Vector2u Settings::getCurrentResolution() {
	return this->resolutions[resolution];
}

std::vector<sf::Vector2u> &Settings::getResolutions() {
	return this->resolutions;
}
int Settings::getResolutionInt()
{
	return this->resolution;
}

bool Settings::getSoundBackground() {
	return this->SoundBackground;
}

bool Settings::getSoundEnemy() {
	return this->SoundEnemy;
}

bool Settings::getSoundPlayer() {
	return this->SoundPlayer;
}

int Settings::getVolumeMusic() {
	return this->volumeMusic;
}
int Settings::getVolumeSound() {
	return this->volumeSound;
}
bool Settings::isFullscreen() {
	return this->fullscreen;
}
void Settings::changeSettings(int reso, bool enemySound, bool playerSound, bool backgroundSound, int volumeMusic, int volumeSound)
{
	this->resolution = reso;
	this->SoundBackground = backgroundSound;
	this->SoundEnemy = enemySound;
	this->SoundPlayer = playerSound;
	this->volumeSound = volumeSound;
	this->volumeMusic = volumeMusic;
}