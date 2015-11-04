#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
	public:
		//Boss(int life, int dommage,int LaserSpeed, int speed, int rate, sf::Texture&, sf::Vector2f)
		Boss(TypeEnemy * Typenemy, sf::Texture& texture,sf::Texture& explode, sf::Vector2f pos);
		//Boss(const Boss &);
		~Boss();
		//Déplace le boss
		void move();
		//Idem
		void move(sf::Sprite & sprite);
		//Modifie la position du boss
		void setPosition(float,float);
		//Permet de tirer
		vector<Laser*> shoot(sf::Texture &texture);
};

