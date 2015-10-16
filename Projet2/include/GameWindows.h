#pragma once
#include "Windows.h"
#include "Field.h"
#include <string>
using namespace std;

class GameWindows : public Windows
{
public: 
	GameWindows(int w, int h, string name,bool available);
	void runWindows();
	void endInit();
	void setAvalaible(bool);

private :
	bool avalaible;
	Field * field;
};

