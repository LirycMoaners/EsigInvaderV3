#pragma once

#include "Weapon.h"
#include "SpaceObject.h"

//définit le player courant
class Spaceship: public SpaceObject
{
	private:
		//le vecteur selection d'image de texture pour faire l'animation
		sf::Vector2i anim;
		// l'arme du joueur
		Weapon weapon;

	public:
		//Spaceship(sf::Texture&)
		Spaceship(sf::Texture&,sf::Texture&);

		Weapon &getWeapon();

		///<summary>
		///déplace l'objet courant selon une direction choisie dans une énumération. 
		///<param int='dir'>direction de déplacement</param>
		///</summary>
		void move(int);

		//Selectionne les images par rapport au movement
		void switchFps();
		~Spaceship();
};
