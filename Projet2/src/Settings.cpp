#include "..\include\Settings.h"

using namespace std;

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

string Settings::getResolution() {
	return this->resolution;
}
void Settings::setResolution(string reso) {
	this->resolution = reso;
}

bool Settings::getSoundBackground() {
	return this->setSoundBackground;
}
void Settings::setSoundBackground(bool back) {
	this->setSoundBackground = back;
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