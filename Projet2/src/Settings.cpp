#include "..\include\Settings.h"

using namespace std;

Settings::Settings(std::string reso, bool enemySound, bool playerSound, bool backgroundSound, int volumeMusic, int volumeSound)
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

string Settings::getResolution() {
	return this->resolution;
}
void Settings::setResolution(string reso) {
	this->resolution = reso;
}

bool Settings::getSoundBackground() {
	return this->SoundBackground;
}
void Settings::setSoundBackground(bool back) {
	this->SoundBackground = back;
}

bool Settings::getSoundEnemy() {
	return this->SoundEnemy;
}
void Settings::setSoundEnemy(bool enemy) {
	this->SoundEnemy = enemy;
}

bool Settings::getSoundPlayer() {
	return this->SoundPlayer;
}
void Settings::setSoundPlayer(bool player) {
	this->SoundPlayer = player;
}

int Settings::getVolumeMusic() {
	return this->volumeMusic;
}
int Settings::getVolumeSound() {
	return this->volumeSound;
}

void Settings::setVolumeMusic(int volume) {
	this->volumeMusic = volume;
}
void Settings::setVolumeSound(int volume) {
	this->volumeSound = volume;
}