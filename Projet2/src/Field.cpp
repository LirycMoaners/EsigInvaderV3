#include "../include/Field.h"

extern int WINDOW_WIDTH;
Field::Field(bool available, Img* img) : bullets(NULL)
{
	this->img = img;
	if (available) {
		c = new Armband();
		if (!c->getStatus()) {
			delete c;
			c = new Keyboard();
		}
	}
	else {
		c = new Keyboard();
	}
	spaceship = new Spaceship(img->getSpaceship_t());
}

Spaceship *Field::getSpaceship()
{
	return spaceship;
}

vector<Bullet*> &Field::getBullets()
{
	return bullets;
}
vector<Enemy*> & Field::getEnemies()
{
	return this->enemies;
}

void Field::addBullets(vector<Bullet *> &b)
{
	vector<Bullet*> bullets = b;
	for (int i = 0; i < bullets.size(); i++)
		this->bullets.push_back(bullets[i]);
}

void Field::removeBullet(int i) {
	delete bullets.at(i);
	bullets.erase(bullets.begin() + i);
}

void Field::control()
{
	if (c != NULL) {
		vector<Bullet*> b = c->shoot(img->getBullet_t(), spaceship);
		c->move(spaceship);
		c->runHub();
		addBullets(b);
		addEnemies();
	}
}
void Field::addEnemies()
{
	if (timer.getElapsedTime().asSeconds() >=2 || enemies.size() == 0)
	{
		Enemy *enemy = new Enemy(WINDOW_WIDTH, 1 + (int)((float)rand() / 32767 * (WINDOW_HEIGHT)- img->getEnemy_t().getSize().y), img->getEnemy_t());
		this->enemies.push_back(enemy);
		timer.restart();

		for (int i = 0; i < enemies.size(); i++)
			addBullets(enemies.at(i)->getWeapon().shoot(img->getBullet_t(), enemies.at(i)->getSprite()));
	}
}

void Field::collision(sf::RenderWindow *window)
{

	// Bullet end of screen width
	for (int i = 0; i < bullets.size(); i++)
		if (bullets.at(i)->getSprite().getPosition().x > window->getSize().x) {
			delete bullets.at(i);
			bullets.erase(bullets.begin() + i);
		}
			
	// Spaceship coll with border of screen width  or height;
	if (spaceship->getSprite().getPosition().x < 0)
		spaceship->getSprite().setPosition(0, spaceship->getSprite().getPosition().y);
	else if (spaceship->getSprite().getPosition().x + spaceship->getSprite().getTextureRect().width > window->getSize().x)
		spaceship->getSprite().setPosition(window->getSize().x - spaceship->getSprite().getTextureRect().width, spaceship->getSprite().getPosition().y);
	
	if (spaceship->getSprite().getPosition().y < 0)
		spaceship->getSprite().setPosition(spaceship->getSprite().getPosition().x, 0);
	else if (spaceship->getSprite().getPosition().y + spaceship->getSprite().getTextureRect().height > window->getSize().y)
		spaceship->getSprite().setPosition(spaceship->getSprite().getPosition().x, window->getSize().y - spaceship->getSprite().getTextureRect().height);	
	enemyCollideSpaceShip();
	bulletCollideEnemy();
	
}

void Field::enemyCollideSpaceShip()
{
	sf::Vector2f spaceshipPos = spaceship->getSprite().getPosition();
	sf::Vector2f spaceshipSize = sf::Vector2f(spaceship->getSprite().getTextureRect().width, spaceship->getSprite().getTextureRect().height);

	for (int i = 0; i < enemies.size(); i++)
	{
		sf::Vector2f enemyPos = enemies.at(i)->getSprite().getPosition();
		sf::Vector2f enemySize = sf::Vector2f(enemies.at(i)->getSprite().getTextureRect().width, enemies.at(i)->getSprite().getTextureRect().height);

		if (enemyPos.x <0)
			enemies.erase(enemies.begin() + i);
		else if(!(enemyPos.y >(spaceshipPos.y + spaceshipSize.y) 
			|| (enemyPos.y + enemySize.y) < spaceshipPos.y 
			|| enemyPos.x > (spaceshipPos.x + spaceshipSize.x) 
			|| (enemyPos.x + enemySize.x) < spaceshipPos.x))
		{
				spaceship->takeDommage(enemies.at(i)->getHealth());
				delete enemies.at(i);
				enemies.erase(enemies.begin() + i);

			}
	}
}
void Field::bulletCollideEnemy()
{
	sf::Vector2f spaceshipPos = spaceship->getSprite().getPosition();
	sf::Vector2f spaceshipSize = sf::Vector2f(spaceship->getSprite().getTextureRect().width, spaceship->getSprite().getTextureRect().height);

	int i = 0;
	for (int j = 0; j < bullets.size();j++)
	{
		sf::Vector2f bulletPos = bullets.at(j)->getSprite().getPosition();
		sf::Vector2f bulletSize = sf::Vector2f(bullets.at(j)->getSprite().getTextureRect().width, bullets.at(j)->getSprite().getTextureRect().height);
		for (int i = 0; i < enemies.size(); i++)
		{
			sf::Vector2f enemyPos = enemies.at(i)->getSprite().getPosition();
			sf::Vector2f enemySize = sf::Vector2f(enemies.at(i)->getSprite().getTextureRect().width, enemies.at(i)->getSprite().getTextureRect().height);
			
			//Collide player's bullets with enemy
			if (!bullets.at(j)->isEnemyBullet())
			{
				if (!(bulletPos.y < enemyPos.y 
					|| bulletPos.y >(enemyPos.y + enemySize.y) 
					|| bulletPos.x + bulletSize.x < enemyPos.x 
					|| bulletPos.x >(enemyPos.x + enemySize.x)))
				{
<<<<<<< HEAD
					if (enemies.at(i)->getSprite().getPosition().x <= bullets.at(j)->getSprite().getPosition().x + bullets.at(j)->getSprite().getTextureRect().width)
						if (bullets.at(j)->getSprite().getPosition().y>enemies.at(i)->getSprite().getPosition().y
							&&bullets.at(j)->getSprite().getPosition().y<(enemies.at(i)->getSprite().getPosition().y + enemies.at(i)->getSprite().getTextureRect().height)
							|| ((bullets.at(j)->getSprite().getPosition().y + bullets.at(j)->getSprite().getTextureRect().height>enemies.at(i)->getSprite().getPosition().y) 
							&& (bullets.at(j)->getSprite().getPosition().y + bullets.at(j)->getSprite().getTextureRect().height < enemies.at(i)->getSprite().getPosition().y + enemies.at(i)->getSprite().getTextureRect().height)))
						{
							enemies.at(i)->takeDommage(this->spaceship->getWeapon().getDommage());
							cout << "dead!!!!" << endl;
							removeBullet(j);
							if (!(enemies.at(i)->isAlive())) {
								delete enemies.at(i);
								enemies.erase(enemies.begin() + i);
							}
							break;
=======
						enemies.at(i)->takeDommage(this->spaceship->getWeapon().getDommage());
						cout << "dead!!!!" << endl;
						removeBullet(j);
						if (!(enemies.at(i)->isAlive())) {
							delete enemies.at(i);
							enemies.erase(enemies.begin() + i);
>>>>>>> cf917a01ec4ce9b3514234c985b1b71c56e26079
						}
						break;
					}
			}

			//Collide ennemies bullets with player
			else
			{
				if (!(bulletPos.y >(spaceshipPos.y + spaceshipSize.y) 
					|| (bulletPos.y + bulletSize.y) < spaceshipPos.y
					|| bulletPos.x > (spaceshipPos.x + spaceshipSize.x)
					|| (bulletPos.x + bulletSize.x) < spaceshipPos.x))
					{
						spaceship->takeDommage(enemies.at(i)->getWeapon().getDommage());
						cout << "Player life: " << spaceship->getHealth() << endl;
						removeBullet(j);
						break;
					}
			}
		}
	}
}
Field::~Field()
{
	delete spaceship;
	delete c;
}