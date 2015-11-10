#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

//Objet parent à tous les objets
class SpaceObject
{
	protected:
		//representation ou texture d'un objet graphique avex toutes ses propriétés
		sf::Sprite sprite;

		//Sprite pour l'explosion du vaisseau
		sf::Sprite explosionSprite;
		//Texture pour les explosions
		sf::Texture& explosionTexture;
		//Vitesse d'actualisation des frames d'explosions
		sf::Clock* explosionFrameSpeed;
		//Frame d'explosion en cours d'affichage
		int explosionFrameCounter = 0;
		//Son de l'explosion
		sf::Sound explosionSound;

		//la vie de la l'objet
		int health;

		//la vitesse de déplacement
		int speed;
		
	public:
		//SpaceObject(sf::Texture &t,int,int)
		SpaceObject(sf::Texture &t,sf::Texture &expt,sf::SoundBuffer& expBuffer,int,int);
		~SpaceObject();

		
		sf::Sprite &getSprite();
		sf::Sprite &getExplosionSprite();
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

	private:
		//Detecte si le vaisseau est en cours d'explosion
		bool isExplosing();
};

