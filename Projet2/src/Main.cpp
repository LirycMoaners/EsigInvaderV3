#pragma region includes
#include <iostream>
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
#include "../include/myo/myo.hpp"
#include "../include/Armhand.h"
#include <../include/SFML/Graphics.hpp>
#include "../include/Field.h"

#pragma endregion includes

#pragma region variables
sf::RenderWindow window;
Field field;


int WIDTH = 800;
int HEIGHT = 600;
#pragma endregion variables

using namespace std;
using namespace myo;

bool initMyo();


int main()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "EsigInvaders");
	window.setFramerateLimit(60);

	bool result;
	Hub hub("com.esiginvaders.move");
	std::cout << "Attempting to find a Myo..." << std::endl;

	// Next, we attempt to find a Myo to use. If a Myo is already paired in Myo Connect, this will return that Myo
	// immediately.
	// waitForMyo() takes a timeout value in milliseconds. In this case we will try to find a Myo for 10 seconds, and
	// if that fails, the function will return a null pointer.
	Myo* myo = hub.waitForMyo(10000);

	// If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
	if (!myo) {
		throw std::runtime_error("Unable to find a Myo!");
		result =  false;
	}
	else {
		result = true;
	}
	// We've found a Myo.
	std::cout << "Connected to a Myo armband! \nLogging to the file system. \nCheck your home folder or the folder this application lives in.\n" << std::endl << std::endl;
	// Next we enable EMG streaming on the found Myo.
	myo->setStreamEmg(myo::Myo::streamEmgEnabled);
	


	Armhand armhand;
	armhand.
	if (result) {
		armhand = Armhand(0,HEIGHT / 2, field);
		hub.addListener(&armhand);
		field = armhand.getField();
	}
	else {
		field = Field(false);
	}
	
	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!result) {
			field.control();
		}
		field.collision(window);

		window.clear();
		for (int i = 0; i < field.getBullets().size(); i++)
		{
			field.getBullets()[i].move();
			window.draw(field.getBullets()[i].getShape());
		}
		window.draw(field.getSpaceship().getShape());
		window.display();
	}

	return 0;
}

bool initMyo() {
	
	

	return true;
}