#pragma once

#include "Weapon.h"
#include "SpaceObject.h"

//d�finit le player courant
class Spaceship: public SpaceObject
{
	private:
		//le vecteur selection d'image de texture pour faire l'animation
		sf::Vector2i anim;
		// l'arme du joueur
		Weapon weapon;
		//Valeur maximale de la vie du player
		int HEALTH_MAX = 1500;

	public:
		//Spaceship(sf::Texture&)
		Spaceship(sf::Texture&,sf::Texture&, sf::SoundBuffer&, sf::SoundBuffer&);

		Weapon &getWeapon();

		///<summary>
		///d�place l'objet courant selon une direction choisie dans une �num�ration. 
		///<param int='dir'>direction de d�placement</param>
		///</summary>
		void move(int);


		void setHealth(int life, bool changeMax = false);
		//Retourne la vie maximal du spaceship
		int getHealthMax();

		//Selectionne les images par rapport au movement
		void switchFps();
		~Spaceship();
};
