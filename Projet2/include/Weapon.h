#pragma once

#include <iostream>
#include "SFML/Audio.hpp"
#include "Rocket.h"
#include "Img.h"

class Weapon
{
	private:
		//Niveau
		int level;
		//quantité de balles
		int rocketQty;
		//Le nombre de balles tirées par l'arme
		int rate;
		// la vitesse de déplacement de la balle
		int speed;
		// Détermine le tireur de la balle
		bool enemyWeapon;
		//Définit la force de dégât de l'arme
		int dommage;
		//Son à jouer lors du tir
		sf::Sound gunSound;

	public:
		//Weapon(bool enemy = false)
		Weapon(sf::SoundBuffer& wpSnd, bool enemy = false);
		//Weapon(int, bool enemy = false)
		Weapon(sf::SoundBuffer& wpSnd,int, bool enemy = false);
		int getRate();
		int getLvl();
		///Permet au propriétaire de l'arme de tirer. 
		vector<Rocket*> shoot(sf::Texture&, sf::Sprite);
		//définit le niveau
		void setLvl(int);
		int getDommage();
		~Weapon();
};