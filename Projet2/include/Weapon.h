#pragma once
#include <iostream>
#include <vector>
#include "SFML/Audio.hpp"
#include "Rocket.h"
#include "Img.h"
#include "Resources.h"

class Weapon
{
	private:
		//Niveau
		int level;
		//quantit� de balles
		int rocketQty;
		//Le nombre de balles tir�es par l'arme
		int rate;
		// la vitesse de d�placement de la balle
		int speed;
		// D�termine le tireur de la balle
		bool enemyWeapon;
		//D�finit la force de d�g�t de l'arme
		int dommage;
		//Son � jouer lors du tir
		sf::Sound gunSound;

	public:
		//Weapon(bool enemy = false)
		Weapon(Resources &res, bool enemy = false);
		//Weapon(int, bool enemy = false)
		Weapon(Resources &res, int value, bool enemy = false);
		int getRate();
		int getLvl();
		///Permet au propri�taire de l'arme de tirer. 
		std::vector<Rocket*> shoot(sf::Texture& texture, sf::Sprite sprite);
		//d�finit le niveau
		void setLvl(int);
		int getDommage();
		~Weapon();
};