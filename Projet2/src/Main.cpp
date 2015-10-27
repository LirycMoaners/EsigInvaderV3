#include "../include/Menu.h"

using namespace std;

int main()
{
	/*;	
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
	game.runWindows();*/
	srand(time(NULL));
	Menu menu = Menu(1024,700,"EsigInvader");
	menu.runWindows();

	return 0;
}




