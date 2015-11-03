#pragma once
#include <SFML\Graphics.hpp>
#include "SpaceObject.h"
#include <iostream>
#include "Laser.h"
#include "TypeEnemy.h"

class Enemy : public SpaceObject
{
	protected:
		//Force de dégâts
		int dommage;
		//Vérifie si l'ennemi se déplace vers le bas
		bool moveDown;
		//Le vecteur selection d'image de texture pour faire l'animation
		sf::Vector2i anim;
		//Définit la quatité de lasers qu'il tire à la fois
		int laserQty;
		//Fréquence des lasers
		int rate;
		//La vitesse des lasers
		int laserSpeed;
		//Compte le numbre d'ennemis
		int compteurEnemy;
		//Vérifie si l'ennemi est le boss
		bool boss = false;

	public:
		//Enemy(float, float, sf::Texture&);
		Enemy(sf::Texture&, sf::Vector2f);
		//Enemy(float, float, sf::Texture&,int, int)
		Enemy(sf::Texture&, sf::Vector2f, int, int);
		Enemy(sf::Texture &t, sf::Vector2f pos, TypeEnemy * enemy);
		int getDommage();
		// selectionne les images par rapport au movement
		void switchFps();
		//Methode de tire des lasers de l'ennemi
		vector<Laser*> shoot(sf::Texture&);
		//Définit le niveau d'appartenance de l'ennemi
		void setLvl(int);

		//déplace l'objet courant. 
		void move();
		//TODO à supprimer
		bool getType();
		~Enemy();
};

