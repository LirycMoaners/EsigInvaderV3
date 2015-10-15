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



class Armband : public Control
{
private:
	int compteurSpace;
	DataCollector * collector;
	myo::Hub * hub;
	bool status;
public:
	Armband();
	void runHub();
	void move(Spaceship&);
	vector<Bullet> shoot(sf::Texture&, Spaceship&);
	~Armband();
	bool getStatus();
};

