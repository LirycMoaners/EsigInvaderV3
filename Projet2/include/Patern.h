#pragma once
#include "tinyxml2.h"
#include "Enemy.h"
#include <vector>

class Patern
{
	private:
		//Permet de charger un pattern depuis le fichier xml des patterns.
		tinyxml2::XMLElement * patern;
		//TODO supprimer certains de ces attributs
		int typeEnemy;
		int lvlEnemy;
		int time;
		int duree;

	public:
		//Patern()
		Patern();
		//Patern(tinyxml2::XMLDocument&, int)
		Patern(tinyxml2::XMLDocument&, int);
		//Alimente le hub avec les ennemis
		std::vector<Enemy*> spawn(Resources &res, TypeEnemy * typeenemy, bool pony, int displayEnemies, int height, int width);
		int next();
		~Patern();
};
