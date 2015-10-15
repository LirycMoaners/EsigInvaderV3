#include "..\include\Armband.h"


Armband::Armband(){
	compteurSpace = 1;
	try {
		// First, we create a Hub with our application identifier. Be sure not to use the com.example namespace when
		// publishing your application. The Hub provides access to one or more Myos.
		//hub();
		hub = new myo::Hub("com.esigInvader.armband");
		std::cout << "Attempting to find a Myo..." << std::endl;

		// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
		// immediately.
		// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
		// if that fails, the function will return a null pointer.
		myo::Myo* myo = hub->waitForMyo(10000);

		// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
		if (!myo) {
			throw std::runtime_error("Unable to find a Myo!");
			this->status = false;
		}
		else {
			// We've found a Myo.
			std::cout << "Connected to a Myo armband! \nLogging to the file system. \nCheck your home folder or the folder this application lives in.\n" << std::endl << std::endl;

			// Next we enable EMG streaming on the found Myo.
			myo->setStreamEmg(myo::Myo::streamEmgEnabled);

			// Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
			this->collector = new DataCollector();
			// Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
			// Hub::run() to send events to all registered device listeners.
			hub->addListener(collector);

			this->status = true;
		}


	}
	catch (const std::exception& e) {
		this->status = false;
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Press enter to continue.";
		std::cin.ignore();
	}
}

bool Armband::getStatus() {
	return this->status;
}

void Armband::runHub() {
	this->hub->run(1000 / 20);
}

vector<Bullet> Armband::shoot(sf::Texture&texture, Spaceship&s) {
	myo::Pose pose = this->collector->getPose();
	if (pose == myo::Pose::fist || pose == myo::Pose::fingersSpread) {

		
		if (60 / compteurSpace == s.getWeapon().getRate())
		{
			vector<Bullet> bu = s.getWeapon().shoot(texture, s.getSprite());
			compteurSpace = 1;
			return bu;
		}
		else
			compteurSpace++;
	}
}


void Armband::move(Spaceship &s)
{

}
Armband::~Armband()
{
}
