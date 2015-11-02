#include "../include/DataCollector.h"

DataCollector::DataCollector()
{
	
}

DataCollector::~DataCollector()
{

}

void DataCollector::onBatteryLevelReceived(myo::Myo * 	myo, uint64_t 	timestamp, uint8_t 	level) {
	if (level < 10) {
		this->battery = false;
	}
	else {
		this->battery = true;
	}
}

bool DataCollector::getBattery() {
	return this->battery;
}
// onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
// making a fist, or not making a fist anymore.
void DataCollector::onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
{
	this->currentPose = pose;
}

myo::Pose DataCollector::getPose(){
	return currentPose;
}

myo::Vector3< float > & DataCollector::getGyro(){
	return gyro;
}

void DataCollector::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
	
	this->gyro = gyro;
}
void DataCollector::onOrientationData(myo::Myo *myo, uint64_t timestamp, const myo::Quaternion< float > &rotation) {
	this->orien = rotation;
}
myo::Quaternion< float > & DataCollector::getOrient(){
	return this->orien;
}

void DataCollector::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
}

