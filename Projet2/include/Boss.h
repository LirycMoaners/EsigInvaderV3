#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
	public:
		//Boss(int life, int dommage,int LaserSpeed, int speed, int rate, sf::Texture&, sf::Vector2f)
		Boss(TypeEnemy * Typenemy, sf::Texture& texture,sf::Texture& explode, sf::Vector2f pos);
		//Boss(const Boss &);
		~Boss();
		//Vie max du boss
		int HEALTH_MAX;
		//D�place le boss
		void move();
		//Idem
		void move(sf::Sprite & sprite);
		//Modifie la position du boss
		void setPosition(float,float);
		//Retourne � vie max du boss
		int getHealthMax();
		//Permet de tirer
		vector<Laser*> shoot(sf::Texture &texture);
};

