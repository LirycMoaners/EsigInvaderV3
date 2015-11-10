#pragma once

#include "tinyxml2.h"
#include "Enemy.h"


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
		vector<Enemy*> spawn(sf::Texture &t,sf::Texture &expt,sf::SoundBuffer& expBuffer, TypeEnemy * typeenemy, bool pony);
		///<summary>
		///retourne 0 si le niveau n'est pas terminé et 1 sinon
		///<return>int </return>
		///</summary>
		int next();
		~Patern();
};
