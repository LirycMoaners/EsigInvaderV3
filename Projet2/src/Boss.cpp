#include "..\include\Boss.h"

Boss::Boss(TypeEnemy * Typenemy, sf::Texture& texture, sf::Texture& Explode, sf::SoundBuffer& expBuffer, sf::Vector2f pos) : Enemy(texture, Explode,expBuffer,  pos, Typenemy, 0, false)
{
	sprite.setPosition(sprite.getPosition().x - sprite.getGlobalBounds().width - 100, sprite.getPosition().y);
	sprite.setTextureRect(sf::IntRect(rand() % 4 * 131, 0, 131, 189));

	HEALTH_MAX = Typenemy->getLife();
}

void Boss::move(){
	sprite.move(-speed, 0);
}

void Boss :: move(sf::Sprite & sprite) {
	int posPlayer = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
	int posBoss = this->getSprite().getPosition().y + this->getSprite().getGlobalBounds().height / 2;
	if (posPlayer != posBoss) {
		int delta = this->speed  * (posPlayer -posBoss ) < 0 ? -1 : 1;
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

int Boss::getHealthMax() { return HEALTH_MAX; }