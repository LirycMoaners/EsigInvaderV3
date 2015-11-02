#pragma once

#include <iostream>
#include "Armband.h"
#include "Keyboard.h"
#include "Spaceship.h"
#include "Rocket.h"
#include "Laser.h"
#include "Patern.h"
#include "Img.h"
#include "tinyxml2.h"
#include "Level.h"
#include "Resources.h"

using namespace std;

class Game
{
	private:
		Img *img;
		sf::Font arial;
		sf::RectangleShape background;
		Spaceship spaceship;
		vector<Rocket*> rockets;
		vector<Enemy*> enemies;
		vector<Laser*> lasers;
		tinyxml2::XMLDocument XMLPatern;
		vector<Patern> patern;

		/*
			Configuration XML 			
		*/
		Resources res;
		Boss * boss;
		int curPatern;
		int nbPaternAvailable = 0;
		int curLevel = 0;
		bool popBoss = false;

	public:
		Control *c;
		sf::RenderWindow *window;
		Game();
		Game(sf::RenderWindow&, Resources & res);
		Spaceship &getSpaceship();
		vector<Rocket*> &getRockets();
		vector<Enemy*> &getEnemies();
		vector<Laser*> &getLasers();
		void runGame();
		void addRockets(vector<Rocket*>&);
		void addLasers(vector<Laser*>&);
		void addEnemies(vector<Enemy*>&);
		void addBoss();
		void control();
		void moveBackground();
		void collision();
		~Game();
};