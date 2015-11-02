#include "..\include\Level.h"

using namespace std;
Level::Level(int nb, string background )
{
	this->nbPatern = nb;
	this->urlImage = background;
}

int Level::getNbPatern() {
	return this->nbPatern;
}
string Level::getUrlImage() {
	return urlImage;
}

Level::~Level()
{
}
