#pragma once
#include "Windows.h"
#include "Field.h"
#include "Level.h"
#include <string>
#include <vector>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

class GameWindows : public Windows
{
public: 
	GameWindows(int w, int h, string name,bool available);
	void runWindows();
	void endInit();
	void setAvalaible(bool);
	void loadData();
private :
	bool avalaible;
	Field * field;
	vector<Level> levels;
};

