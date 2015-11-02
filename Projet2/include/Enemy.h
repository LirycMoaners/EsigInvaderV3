#pragma once
#include <SFML\Graphics.hpp>
#include "SpaceObject.h"
#include <iostream>
#include "Laser.h"

class Enemy : public SpaceObject
{
	protected:
		//Force de d�g�ts
		int dommage;
		//La vie de l'ennemi
		int life;
		//V�rifie si l'ennemi se d�place vers le bas
		bool moveDown;
		//Le vecteur selection d'image de texture pour faire l'animation
		sf::Vector2i anim;
		//TODO doublon vitesse ennemi
		int speed = 10;
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
		//Enemy(float, float, sf::Texture&);
		Enemy(sf::Texture&, sf::Vector2f);
		//Enemy(float, float, sf::Texture&,int, int)
		Enemy(sf::Texture&, sf::Vector2f, int, int);

		int getDommage();
		// selectionne les images par rapport au movement
		void switchFps();
		//Methode de tire des lasers de l'ennemi
		vector<Laser*> shoot(sf::Texture&);
		//D�finit le niveau d'appartenance de l'ennemi
		void setLvl(int);

		//d�place l'objet courant. 
		void move();
		//TODO � supprimer
		bool getType();
		~Enemy();
};

