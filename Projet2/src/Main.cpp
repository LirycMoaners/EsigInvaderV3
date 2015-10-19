#pragma region includes
#include <iostream>
#include <string>
#include <stdio.h>
#include "../include/Global.h"
#include <../include/SFML/Graphics.hpp>
#include "../include/myo/libmyo.h"
#include "../include/Field.h"
#include "../include/Windows.h"
#include "../include/GameWindows.h"
#pragma endregion includes

using namespace std;
std::string exec(const char* cmd);

extern int WINDOW_WIDTH = 800;
extern int WINDOW_HEIGHT = 600;

int main()
{

	srand(time(NULL));
	//Windows size
	

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
	GameWindows game(WINDOW_WIDTH, WINDOW_HEIGHT, title,available);
	game.runWindows();
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