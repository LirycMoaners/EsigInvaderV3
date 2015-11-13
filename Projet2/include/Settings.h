#pragma once
#include <iostream>
#include <string>

class Settings
{
public:
	Settings(std::string reso, bool enemySound,bool playerSound, bool backgroundSound, int volumeMusic, int volumeSound);
	~Settings();

	bool getSoundEnemy();
	bool getSoundPlayer();
	bool getSoundBackground();
	int getVolumeMusic();
	int getVolumeSound();
	void setSoundEnemy(bool);
	void setSoundPlayer(bool);
	void setSoundBackground(bool);
	void setVolumeMusic(int);
	void setVolumeSound(int);

	std::string getResolution();
	void setResolution(std::string reso);

private : 
	std::string resolution;
	bool SoundEnemy = true;
	bool SoundPlayer = true;
	bool SoundBackground = true;
	int volumeMusic;
	int volumeSound;
};

