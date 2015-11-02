#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
class Bullet
{
	protected:
		sf::Sprite sprite;
		int anim;
		int speed;
		int dommage;
		bool enemyBullet = false;

	public:
		//Bullet()
		Bullet();
		//Bullet(sf::Texture&, sf::Vector2f, int, bool enemy);
		Bullet(sf::Texture&, int,int,sf::Sprite, int,int, float = 1);
		Bullet(const Bullet&);

		sf::Sprite &getSprite();
		void move();
		int getDommages();
		//Permet de vérifier si la balle est celle d'un ennemi
		bool isEnemyBullet();
		// selectionne les images par rapport au movement
		void switchFps();
		~Bullet();
};
