#pragma once
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
#include "Field.h"
#include ".\myo\myo.hpp"

class Armhand
{
public:
	Armhand(int previous_value, Field &field);
	~Armhand();
	void end();
private : 
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro);
	void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);
	void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
	int previous_y;
	Field field;
	myo::Pose currentPose;
};

