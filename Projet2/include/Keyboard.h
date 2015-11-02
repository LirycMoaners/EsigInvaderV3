#pragma once

#include <iostream>
#include "Spaceship.h"
#include "Control.h"

class Keyboard : public Control
{
	private:
		//Control ou d�finit l'espace entre deux tirs.
		int compteurSpace;
	public:
		//Keyboard()
		Keyboard();
		//Useless
		bool getStatus();
		//Methode qui permet de lancer le hub.
		void runHub();
		//Methode qui fait d�placer le player
		void move(Spaceship&);
		//Permet au player de tirer
		vector<Rocket*> shoot(sf::Texture&, Spaceship&);
		//Retourne true si la touche �chappe est appuy�e ou si le programme est arret� sinon False.
		bool quit();
		~Keyboard();
};