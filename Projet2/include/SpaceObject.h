#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

//Objet parent � tous les objets
class SpaceObject
{
	protected:
		//representation ou texture d'un objet graphique avex toutes ses propri�t�s
		sf::Sprite sprite;

		//Sprite pour l'explosion du vaisseau
		sf::Sprite explosionSprite;
		//Texture pour les explosions
		sf::Texture& explosionTexture;
		//Vitesse d'actualisation des frames d'explosions
		sf::Clock* explosionFrameSpeed;
		//Frame d'explosion en cours d'affichage
		int explosionFrameCounter = 0;

		//la vie de la l'objet
		int health;

		//la vitesse de d�placement
		int speed;
		
	public:
		//SpaceObject(sf::Texture &t,int,int)
		SpaceObject(sf::Texture &t,sf::Texture &expt,int,int);
		~SpaceObject();

		
		sf::Sprite &getSprite();
		sf::Sprite &getExplosionSprite();
		virtual void move() {};

		int getHealth();
		int getSpeed();

		///<summary>
		///methode appel�e lors d'une collision pour signifier que l'objet a r��u un dommage et ainsi diminue la valeur de vie
		///</summary>
		void takeDommage(int dommage);
		///<summary>
		///retourne vrai si l'objet est vivant sinon faux.
		///</summary>
		bool isAlive();

	private:
		//Detecte si le vaisseau est en cours d'explosion
		bool isExplosing();
};

