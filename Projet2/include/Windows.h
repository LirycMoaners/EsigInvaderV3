#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
class Windows
{
	public:
		Windows();
		Windows(int width, int height, string nameWindows);
		~Windows();
		void setWidth(int);
		void setHeight(int);
		void setTitle(string);
		virtual void runWindows() = 0;

	protected:
		int width;
		int height;
		string title;
		sf::RenderWindow *window;
};

