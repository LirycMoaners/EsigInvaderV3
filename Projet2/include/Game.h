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
		int curPatern;

	public:
		Control *c;
		sf::RenderWindow *window;
		Game();
		Game(sf::RenderWindow&);
		Spaceship &getSpaceship();
		vector<Rocket*> &getRockets();
		vector<Enemy*> &getEnemies();
		vector<Laser*> &getLasers();
		void runGame();
		void addRockets(vector<Rocket*>&);
		void addLasers(vector<Laser*>&);
		void addEnemies(vector<Enemy*>&);
		void control();
		void moveBackground();
		void collision();
		~Game();
};