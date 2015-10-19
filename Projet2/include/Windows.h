#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
class Windows
{
public:
	Windows();
	Windows(int width, int height, string nameWindows, bool available);
	~Windows();
	void setWidth(int);
	void setHeight(int);
	void setTitle(string);
	virtual void endInit() = 0;
	virtual void runWindows() = 0;
private : 
	
	
	

protected:
	int width;
	int height;
	string title;
	sf::RenderWindow * window;
	sf::Clock clk;
	int fpsCount = 0;
	int fpsSwitch = 200;
	bool available;
};

