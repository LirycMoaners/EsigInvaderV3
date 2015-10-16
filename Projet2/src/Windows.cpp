#include "..\include\Windows.h"



Windows::Windows(int width, int height, string nameWindows, bool available)
{
	this->setWidth(width);
	this->setHeight(height);
	this->setTitle(nameWindows);
	this->window = new sf::RenderWindow();
	sf::VideoMode test(1024, 800);
	this->window->create(test,"test");
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

}
