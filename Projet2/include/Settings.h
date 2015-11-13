#pragma once
#include <iostream>
#include <string>

class Settings
{
public:
	Settings(std::string reso, bool enemySound,bool playerSound, bool backgroundSound);
	~Settings();

	bool getSoundEnemy();
	bool getSoundPlayer();
	bool getSoundBackground();
	void setSoundEnemy(bool);
	void setSoundPlayer(bool);
	void setSoundBackground(bool);

	std::string getResolution();
	void setResolution(std::string reso);

private : 
	std::string resolution;
	bool SoundEnemy = true;
	bool SoundPlayer = true;
	bool SoundBackground = true;
};

