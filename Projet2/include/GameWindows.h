#pragma once
#include "Windows.h"
#include "Field.h"
#include <string>
#include "MainMenu.h"

using namespace std;

class GameWindows : public Windows
{
public: 
	GameWindows(int w, int h, string name,bool available);
	void runWindows();
	void play();
	void endInit();
	void setAvalaible(bool);

private :
	bool avalaible;
	Field * field;
};

