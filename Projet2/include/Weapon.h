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
		Weapon(Resources &res, bool enemy = false);
		//Weapon(int, bool enemy = false)
		Weapon(Resources &res, int value, bool enemy = false);
		int getRate();
		int getLvl();
		///Permet au propriétaire de l'arme de tirer. 
		std::vector<Rocket*> shoot(sf::Texture& texture, sf::Sprite sprite);
		//définit le niveau
		void setLvl(int);
		int getDommage();
		~Weapon();
};