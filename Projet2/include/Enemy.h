#pragma once
#include <SFML\Graphics.hpp>
#include "SpaceObject.h"
#include <iostream>
#include "Laser.h"
#include "TypeEnemy.h"

class Enemy : public SpaceObject
{
	protected:
		//Force de d�g�ts
		int dommage;
		//V�rifie si l'ennemi se d�place vers le bas
		bool moveDown;
		//Le vecteur selection d'image de texture pour faire l'animation
		sf::Vector2i anim;
		//D�finit la quatit� de lasers qu'il tire � la fois
		int laserQty;
		//Fr�quence des lasers
		int rate;
		//La vitesse des lasers
		int laserSpeed;
		//Compte le numbre d'ennemis
		int compteurEnemy;
		//V�rifie si l'ennemi est le boss
		bool boss = false;
	public:
		Enemy(sf::Texture &t, sf::Vector2f pos, TypeEnemy * enemy, int type);
		int getDommage();
		// selectionne les images par rapport au movement
		void switchFps();
		//Methode de tire des lasers de l'ennemi
		vector<Laser*> shoot(sf::Texture&);
		//d�place l'objet courant. 
		void move();
		//TODO � supprimer
		bool getType();
		~Enemy();
};

