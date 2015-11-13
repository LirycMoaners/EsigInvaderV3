#pragma once
#include <iostream>
#include <string>

class Settings
{
public:
	Settings(std::string reso, bool enemySound,bool playerSound, bool backgroundSound);
	~Settings();

private : 
	std::string resolution;
	bool SoundEnemy = true;
	bool SoundPlayer = true;
	bool SoundBackground = true;
};

