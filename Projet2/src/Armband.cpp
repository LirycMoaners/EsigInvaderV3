#include "..\include\Armband.h"

Armband::Armband() {
	compteurSpace = 1;
	string value = exec("tasklist /FI \"imagename eq Myo Connect.exe\" /svc");

	if (value.find("Myo Connect.exe") != -1) {
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
			myo::Myo* myo = hub->waitForMyo(2000);

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
				if (collector->getBattery())
					this->status = true;
				else {
					this->status = false;
					std::cout << "No enough battery" << endl;
					std::cout << "Keyboard Mod Launch" << endl;
				}

				runHub();

				pos_z = 1000;
				pos_y = 1000;
			}
		}
		catch (const std::exception& e) {
			this->status = false;
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	else
	{
		this->status = false;
		std::cerr << "MyoConnect is not launched!";
	}
}

bool Armband::getStatus() {
	return this->status;
}

void Armband::runHub() {
	this->hub->run(1000 / 60);
}

vector<Rocket*> Armband::shoot(sf::Texture&texture, Spaceship *s) {
	vector<Rocket*> r;
	if (this->collector->getPose() == myo::Pose::fist)
	{
		if (60 / compteurSpace == s->getWeapon().getRate())
		{
			r = s->getWeapon().shoot(texture, s->getSprite());
			compteurSpace = 1;
			return r;
		}
		else if (compteurSpace < 60)
			compteurSpace++;
		else {
			compteurSpace = 1;
		}
	}

	return r;
}


void Armband::move(Spaceship *s)
{
	myo::Quaternion< float > orient = this->collector->getOrient();

	if (pos_y == 1000 && pos_z == 1000)
	{
		pos_y = orient.y();
		pos_z = orient.z();
	}

	float capDetect = 0.08;

	if (orient.z() > pos_z + capDetect || orient.z() < pos_z - capDetect || orient.y() > pos_y + capDetect || orient.y() < pos_y - capDetect)
	{
		if (orient.z() > pos_z + capDetect)
			s->move(3);
		else if (orient.z() < pos_z - capDetect)
			s->move(4);

		if (orient.y() > pos_y + capDetect)
			s->move(1);
		else if (orient.y() < pos_y - capDetect)
			s->move(2);
	}
	else
		s->move(0);
}

bool Armband::quit()
{
	if (this->collector->getPose() == myo::Pose::doubleTap)
		return true;
	else
		return false;
}

string Armband::exec(const char* cmd) {
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) return "ERROR";
	char buffer[128];
	std::string result = "";
	while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	_pclose(pipe);
	return result;
}

Armband::~Armband()
{
	collector->~DataCollector();
}
