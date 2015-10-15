#include "../include/DataCollector.h"



/*DataCollector::DataCollector(int previous_value_x,int previous_value_y)
{
	this->previous_y = previous_value_x;
	this->previous_y = previous_value_y;
}*/

DataCollector::DataCollector()
{
	
}

DataCollector::~DataCollector()
{

}

// onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
// making a fist, or not making a fist anymore.
void DataCollector::onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
{
	this->currentPose = pose;
}

myo::Pose DataCollector::getPose() {
	return currentPose;
}

myo::Vector3< float > & DataCollector::getGyro() {
	return gyro;
}

void DataCollector::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
	
	this->gyro = gyro;


	//this->field.getSpaceship().YMove(delta, sens);
}

void DataCollector::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
	//Reneable streaming
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	//openFiles();
}

// Helper to print out accelerometer and gyroscope vectors
/*void DataCollector::printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector) {
	file << timestamp
		<< ',' << vector.x()
		<< ',' << vector.y()
		<< ',' << vector.z()
		<< std::endl;
}

void DataCollector::printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector) {
}

void DataCollector::printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector) {
}


void DataCollector::end () {
}*/
