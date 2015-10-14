#include "../include/Armhand.h"



Armhand::Armhand(int previous_value, Field &field)
{
	this->previous_y = previous_value;
	this->field = field;
}


Armhand::~Armhand()
{

}

// onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
// making a fist, or not making a fist anymore.
void Armhand::onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
{
	this->currentPose = pose;
	if (pose != myo::Pose::fist) {
		this->field.getSpaceship().getWeapon().shoot(this->field.getSpaceship().getShape().getPosition());
	}
	else {
		//this->field.shoot(false);
		// Tell the Myo to stay unlocked only for a short period. This allows the Myo to stay unlocked while poses
		// are being performed, but lock after inactivity.
	}
}

void Armhand::onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &gyro) {
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

void Armhand::onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) {
	//Reneable streaming
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	//openFiles();
}

// Helper to print out accelerometer and gyroscope vectors
/*void Armhand::printVector(std::ofstream &file, uint64_t timestamp, const myo::Vector3< float > &vector) {
	file << timestamp
		<< ',' << vector.x()
		<< ',' << vector.y()
		<< ',' << vector.z()
		<< std::endl;
}

void Armhand::printVectorGyro(uint64_t timestamp, const myo::Vector3< float > &vector) {
}

void Armhand::printVectorAcce(uint64_t timestamp, const myo::Vector3< float > &vector) {
}


void Armhand::end () {
}*/
