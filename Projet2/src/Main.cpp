#include "../include/Menu.h"
#include "../include/Resources.h"
using namespace std;

int main()
{
	// Initialisation du random 
	srand(time(NULL));
	// Création de la fenetre
	Resources res = Resources();
	Menu *menu = new Menu(1024,700,"EsigInvader",res);
	menu->runWindows();

	return 0;
}




