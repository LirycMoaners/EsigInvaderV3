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
		//D�finit le nombre de patterns de d�placement des ennemis
		int nbPatern;
		//D�finit l'url de l'image
		std::string urlImage;
};

