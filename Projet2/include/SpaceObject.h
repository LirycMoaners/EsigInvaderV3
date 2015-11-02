#pragma once
#include "SFML/Graphics.hpp"

//Objet parent à tous les objets
class SpaceObject
{
	protected:
		//representation ou texture d'un objet graphique avex toutes ses propriétés
		sf::Sprite sprite;
		//la vie de la l'objet
		int health;

		//la vitesse de déplacement
		int speed;
		
	public:
		SpaceObject();
		SpaceObject(sf::Texture &t,int,int);
		~SpaceObject();

		
		sf::Sprite &getSprite();
		virtual void move() {};

		int getHealth();
		int getSpeed();

		///<summary>
		///methode appelée lors d'une collision pour signifier que l'objet a réçu un dommage et ainsi diminue la valeur de vie
		///</summary>
		
		void takeDommage(int dommage);
		///<summary>
		///retourne vrai si l'objet est vivant sinon faux.
		///</summary>
		bool isAlive();
};

