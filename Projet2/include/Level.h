#pragma once
#include<string>
#include "Boss.h"
#include "TypeEnemy.h"


class Level
{
	public:
		//Level(int nbPatern,string url)
		Level(int nbPatern,std::string url);
		int getNbPatern();
		std::string getUrlImage();
		~Level();
	private : 
		//Définit le nombre de patterns de déplacement des ennemis
		int nbPatern;
		//Définit l'url de l'image
		std::string urlImage;
};

