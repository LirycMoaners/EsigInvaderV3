#pragma region includes
#include <iostream>
#include <string>
#include <stdio.h>
#include <../include/SFML/Graphics.hpp>
#include "../include/myo/libmyo.h"
#include "../include/Field.h"
#include "../include/Windows.h"
#include "../include/GameWindows.h"
#pragma endregion includes

using namespace std;
std::string exec(const char* cmd);
int main()
{
	//sf::RenderWindow window;
	//sf::Clock clk;
	int fpsCount = 0;
	int fpsSwitch = 200;
	bool available = false;
	string value = exec("tasklist /FI \"imagename eq Myo Connect.exe\" /svc");
	if (value.find("Myo Connect.exe") != -1) {
		available = true;
		cout << "Myo Connect.exe found" << endl;
		cout << value << endl;
	}
	else {
		cout << "No Myo Connect.exe found" << endl;
	}
	string title = "EsigInvaders";
	GameWindows game(800, 600, title,available);
	//game.endInit();
	game.runWindows();

	/*Field field = Field(available);
	
	
	window.create(sf::VideoMode(800, 600), "EsigInvaders");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		field.collision(window);
		field.control();

		if (fpsCount >= fpsSwitch)
		{
			field.getSpaceship().switchFps();
			for (int i = 0; i < field.getBullets().size(); i++)
			{
				field.getBullets()[i].switchFps();
			}
			fpsCount = 0;
		}
		else
			fpsCount += clk.restart().asMilliseconds();

		window.clear();
		for (int i = 0; i < field.getBullets().size(); i++)
		{
			field.getBullets()[i].move();
			window.draw(field.getBullets()[i].getSprite());
		}
		window.draw(field.getSpaceship().getSprite());

		for (int i = 0; i < field.getEnemies().size(); i++)
		{
			field.getEnemies()[i].move();
			window.draw((field.getEnemies()[i]).getShape());
		}
		//cout << "enemi 0 :" << field.getEnemies()[0].getShape().getPosition().x << endl;
		window.display();
	}*/
	return 0;
}




std::string exec(const char* cmd) {
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