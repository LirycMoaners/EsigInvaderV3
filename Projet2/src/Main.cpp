#include "../include/Menu.h"
#include "../include/Resources.h"
using namespace std;

int main()
{
	// Initialisation du random 
	srand(time(NULL));
	// Création de la fenetre
	Resources  res = Resources();
	res.loadResources();

	Menu *menu = new Menu("EsigInvader",res);
	menu->runWindows();
	return 0;
}




