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
	~DataCollector();
	myo::Pose getPose();
	myo::Vector3< float > & getGyro();
	myo::Quaternion< float > & getOrient();
	bool getBattery();
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro);
	void onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation);
	void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);
	void onBatteryLevelReceived(myo::Myo * myo, uint64_t timestamp, uint8_t 	level);

private : 
	void onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion);
	float previous_y;
	myo::Pose currentPose;
	myo::Vector3< float > gyro;
	myo::Quaternion< float > orien;
	bool battery;
};

