#include "..\include\Boss.h"

Boss::Boss(int life, int dommage, int LaserSpeed, int speed,int rate, sf::Texture& texture, sf::Vector2f pos) : Enemy(texture, pos)
{
	this->health = life;
	this->dommage = dommage;
	this->boss = true;
	this->laserSpeed = LaserSpeed;
	this->speed = speed;
	this->rate = rate;
}
void Boss::move(){
	sprite.move(-speed, 0);
}

void Boss :: move(sf::Sprite & sprite) {

	if (sprite.getPosition().y != this->getSprite().getPosition().y) {
		int delta = this->speed  * (sprite.getPosition().y - this->getSprite().getPosition().y) < 0 ? -1 : 1;
		
		this->getSprite().move(0, delta);
	}

}

void Boss::setPosition(float x, float y) {
	if (y < 0)
		y = 0;
	this->sprite.setPosition(x, y);
	int result = rand() % 2;
	if (result) {
		moveDown = false;
	}
	else {
		moveDown = true;
	}
}

Boss::~Boss()
{
	std::cout << "Call Destructor boss" << std::endl;
}


vector<Laser*> Boss::shoot(sf::Texture &texture)
{
	vector<Laser*> l;

	if (compteurEnemy == 60 / rate)
	{
		for (int i = 1; i <= laserQty; i++)
			l.push_back(new Laser(texture, sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + sprite.getTextureRect().height * i / (laserQty + 1) - texture.getSize().y / 12), laserSpeed,this->dommage));

		compteurEnemy = 1;
		return l;
	}
	else
		compteurEnemy++;

	return l;
}