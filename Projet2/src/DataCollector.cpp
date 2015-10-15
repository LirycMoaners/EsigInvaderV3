#include "../include/DataCollector.h"



DataCollector::DataCollector(int previous_value_x,int previous_value_y, Field &field)
{
	this->previous_y = previous_value_x;
	this->previous_y = previous_value_y;
	this->field = field;
}

DataCollector::DataCollector()
{
	
}

DataCollector::~DataCollector()
{

}

Field & DataCollector::getField()
{
	return field;
}

// onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
// making a fist, or not making a fist anymore.
void DataCollector::onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
{
	this->currentPose = pose;
	if (pose != myo::Pose::fist) {
//		this->field.getSpaceship().getWeapon().shoot(this->field.getSpaceship().getSprite().getPosition());
	}
	else {
		//this->field.shoot(false);
		// Tell the Myo to stay unlocked only for a short period. This allows the Myo to stay unlocked while poses
		// are being performed, but lock after inactivity.
	}
}

void DataCollector::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
	bool sens = true;
	unsigned int delta;
	float gyroVal = gyro.y();
	if ((previous_y - gyroVal) < 0) {
		sens = false;
		delta = gyroVal - previous_y;
	}
	else {
		sens = true;
		delta = previous_y - gyroVal;

	}



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
