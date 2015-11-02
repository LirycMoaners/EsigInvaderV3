#include "..\include\Boss.h"

Boss::Boss(int life, int dommage, int LaserSpeed, int speed,int rate, sf::Texture& texture, sf::Vector2f pos) : Enemy(texture, pos)
{
	this->health = life;
	this->dommage = dommage;
	this->boss = true;
	this->laserSpeed = LaserSpeed;
	this->speed = speed;
	this->rate = rate;

	sprite.setTextureRect(sf::IntRect(rand() % 4 * 131, 0, 131, 189));
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
			l.push_back(new Laser(texture, i, laserQty, sprite, laserSpeed,this->dommage));

		compteurEnemy = 1;
		return l;
	}
	else
		compteurEnemy++;

	return l;
}