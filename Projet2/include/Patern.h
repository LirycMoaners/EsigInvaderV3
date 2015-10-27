#pragma once

#include "tinyxml2.h"
#include "Enemy.h"

using namespace std;
class Patern
{
	private:
		tinyxml2::XMLElement *patern;
		int typeEnemy;
		int lvlEnemy;
		int time;
		int duree;

	public:
		Patern();
		Patern(tinyxml2::XMLDocument&, int);
		vector<Enemy*> spawn(sf::Texture&);
		int next();
		~Patern();
};

