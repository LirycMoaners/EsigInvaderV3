#include "..\include\Boss.h"

Boss::Boss(int life, int dommage, sf::Texture& texture) : Enemy(5,5,texture)
{
	this->health = life;
	this->dommage = dommage;
}

void Boss::move(){

	sprite.move(-speed, 0);

	//Change direction when enemy it the border of the window
	if (sprite.getPosition().y < 0 || (sprite.getPosition().y + sprite.getTextureRect().height) > WINDOW_HEIGHT)
		moveDown = !moveDown;

	if (moveDown)
		sprite.move(0, speed);
	else
		sprite.move(0, -speed);
}

void Boss::setPosition(float x, float y) {
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
