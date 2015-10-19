#pragma once
#include "Windows.h"
#include "Field.h"
#include "Level.h"
#include <string>
#include <vector>
#include "tinyxml2.h"
#include "Global.h"
#include "MainMenu.h"

using namespace std;
using namespace tinyxml2;

class GameWindows : public Windows
{
public: 
	GameWindows(int w, int h, string name,bool available);
	void runWindows();
	void play();
	
	protected : 


private :
		int difficulty = 0;
		void loadData(Img*);
		void levelUp();
	bool avalaible;
	Field * field;
		vector<Level *> levels;
	
};

