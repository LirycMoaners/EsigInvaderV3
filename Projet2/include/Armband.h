#pragma once
#include "Control.h"
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <time.h>
#include <direct.h>
#include "myo/myo.hpp"
#include "DataCollector.h"
#include "Laser.h"
#include "Rocket.h"

//TODO commenter cette classe
class Armband : public Control
{
private:
	int compteurSpace;
	DataCollector * collector;
	myo::Hub * hub;
	bool status;
	float pos_z;
	float pos_y;
public:
	Armband();
	void runHub();
	void move(Spaceship*);
	vector<Rocket*> shoot(sf::Texture&, Spaceship*);
	string exec(const char*);
	~Armband();
	bool getStatus();
	bool quit();
};


