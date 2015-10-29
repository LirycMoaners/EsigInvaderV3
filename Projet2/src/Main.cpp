#include "../include/Menu.h"

using namespace std;

int main()
{
	// Initialisation du random 
	srand(time(NULL));
	// Création de la fenetre
	Menu menu = Menu(1024,700,"EsigInvader");
	menu.runWindows();

	return 0;
}




