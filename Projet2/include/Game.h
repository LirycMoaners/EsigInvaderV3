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



class Game
{
	private:
		//Donne accès aux objets graphiques du programme
		Img *img;
		//Police
		sf::Font arial;
		//Graphical object for the background
		sf::RectangleShape background;
		//Instance du player
		Spaceship spaceship;
		//Liste de rocket
		vector<Rocket*> rockets;
		//Liste d'ennemi
		vector<Enemy*> enemies;
		//Liste de lasers
		vector<Laser*> lasers;
		//Fichier xml contenant les patterns
		tinyxml2::XMLDocument XMLPatern;
		//Définit la liste de patterns du jeu
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
		//Lancer le jeu
		void runGame();
		//Charge le fichier configuration et configure le jeu
		void loadingConfiguration();
		//Ajoute des rockets
		void addRockets(vector<Rocket*>&);
		//Ajoute les lasers
		void addLasers(vector<Laser*>&);
		//Ajoute des ennemis
		void addEnemies(vector<Enemy*>&);
		//Ajoute le boss de la partie
		void addBoss();
		//Instacie l'environnement du player
		void control();
		//Gère le mouvement du background
		void moveBackground();
		//collision
		void collision();
		~Game();
};