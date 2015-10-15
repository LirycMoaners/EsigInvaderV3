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
#include "myo\myo.hpp"

class DataCollector : public myo::DeviceListener
{
public:
	DataCollector();
	//DataCollector(int previous_value_x,int previous_value_y, Field &field);
	~DataCollector();
	myo::Pose getPose();
	myo::Vector3< float > & getGyro();
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro);
	void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);
private : 
	void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
	float previous_y;
	myo::Pose currentPose;
	myo::Vector3< float > gyro;
};

