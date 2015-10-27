#pragma once
#include<string>
#include "Boss.h"
#include "TypeEnemy.h"

using namespace std;
class Level
{
	public:
		Level(int nbPatern,string url);
		int getNbPatern();
		string getUrlImage();
		~Level();
	private : 
		int nbPatern;
		string urlImage;
};

