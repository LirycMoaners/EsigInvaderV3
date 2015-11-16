#include "..\include\Windows.h"


using namespace std;

Windows::Windows(int width, int height, bool fullscreen, string nameWindows)
{
	this->setWidth(width);
	this->setHeight(height);
	this->setTitle(nameWindows);
	this->window = new sf::RenderWindow();
	sf::VideoMode video(width, height);
	sf::Uint16 style = fullscreen ? sf::Style::Fullscreen : sf::Style::Close;
	this->window->create(video, nameWindows, style);
	this->window->setFramerateLimit(60);
}

Windows::Windows() {}

void Windows::setTitle(string name) {
	if (strcmp("", name.c_str()) != 0) {
		this->title = name;
	}
}

void Windows::setWidth(int w) {
	if (w > 0) {
		this->width = w;
	}
}
void Windows::setHeight(int h) {
	if(h>0)
		this->height = h;
}


Windows::~Windows()
{
	window->~RenderWindow();
}
