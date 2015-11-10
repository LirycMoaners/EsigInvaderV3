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
#include "GameHub.h"
#include "Bonus.h"

class Game
{
	private:
		
		sf::Font arial;
		//Graphical object for the background
		sf::RectangleShape background;
		//Instance du player
		Spaceship* spaceship;
		//Liste de rocket
		vector<Rocket*> rockets;
		//Liste d'ennemi
		vector<Enemy*> enemies;
		//Liste de lasers
		vector<Laser*> lasers;
		//Musique de fond
		sf::Sound music;
		//Liste des bonus
		vector<Bonus*> bonus;
		//Fichier xml contenant les patterns
		tinyxml2::XMLDocument XMLPatern;
		//Définit la liste de patterns du jeu
		vector<Patern> patern;
		//Hub du jeu pour l'affichage de la vie
		GameHub* gameHub;
		Resources res;
		Boss * boss = NULL;
		int curPatern;
		int nbPaternAvailable = 0;
		int curLevel = 0;
		bool popBoss = false;
		int score = 0;
		bool modeGame = false; // modeGame = false Normal ModeGame = true EndlessMode
		int compteurPatern = 0;
		bool pony = false;
	public:
		Control *c;
		sf::RenderWindow *window;
		//Game();
		Game(sf::RenderWindow&, Resources & res, bool modeGame, string cheat);
		Spaceship *getSpaceship();
		vector<Rocket*> &getRockets();
		vector<Enemy*> &getEnemies();
		vector<Laser*> &getLasers();
		vector<Bonus*> &getBonus();
		//Lancer le jeu
		void runGame();
		//Charge le fichier configuration et configure le jeu
		void PaternGeneration();
		//Ajoute des rockets
		void addRockets(vector<Rocket*>&);
		//Ajoute les lasers
		void addLasers(vector<Laser*>&);
		//Ajoute des ennemis
		void addEnemies(vector<Enemy*>&);
		//Ajoute le boss de la partie
		void addBoss();
		void addBoss(TypeEnemy * type);

		// Activation de cheat
		void activateCheat(string cheat);
		//Instacie l'environnement du player
		void control();
		//Gère le mouvement du background
		void moveBackground();
		//collision
		void collision();
		~Game();
};