#include "../include/Menu.h"

using namespace std;

int main()
{
	// Initialisation du random 
	srand(time(NULL));
	// Cr�ation de la fenetre
	Menu *menu = new Menu(1024,700,"EsigInvader");
	menu->runWindows();

	return 0;
}




