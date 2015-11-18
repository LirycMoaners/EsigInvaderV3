#include "..\include\Img.h"
using namespace std;
Img::Img()
{
	cout << "Loading resources ..." << endl;
	cout << "Loading background" << endl;
	background_t.loadFromFile("ressources/background.jpg");
	cout << "Loading spaceship" << endl;
	spaceship_t.loadFromFile("ressources/spaceship.png");
	cout << "Loading rocket" << endl;
	rocket_t.loadFromFile("ressources/rocket.png");
	cout << "Loading enemy" << endl;
	enemy_t.loadFromFile("ressources/enemy.png");
	cout << "Loading laser" << endl;
	laser_t.loadFromFile("ressources/laser.png");
	cout << "Loading Boss" << endl;
	boss_t.loadFromFile("ressources/Boss.png");
	cout << "Loading home" << endl;
	home_t.loadFromFile("ressources/home.png");
	cout << "Loading button" << endl;
	button_t.loadFromFile("ressources/button.png");
	cout << "Loading explosion" << endl;
	explosion_t.loadFromFile("ressources/explosion.png");
	cout << "Loading bonus_malus" << endl;
	bonus_t.loadFromFile("ressources/bonus_malus.png");
	cout << "Loading buttonOption" << endl;
	button_arrow_t.loadFromFile("ressources/buttonOption.png");
	cout << "Loading settingIcons" << endl;
	settingIco_t.loadFromFile("ressources/settingIcons.png");
	cout << "Loading about" << endl;
	about_t.loadFromFile("ressources/about.png");
	cout << "Loading authors" << endl;
	authors_t.loadFromFile("ressources/authors.png");
}

sf::Texture &Img::getSpaceship_t()
{
	return spaceship_t;
}
sf::Texture &Img::getRocket_t()
{
	return rocket_t;
}
sf::Texture &Img::getLaser_t()
{
	return laser_t;
}
sf::Texture &Img::getBackground_t()
{
	return background_t;
}
sf::Texture &Img::getExplosion_t()
{
	return explosion_t;
}
sf::Texture &Img::getEnemy_t() 
{
	return enemy_t;
}

sf::Texture &Img::getBoss_t()
{
	return boss_t;
}

sf::Texture &Img::getHome_t()
{
	return home_t;
}

sf::Texture &Img::getButton_t()
{
	return button_t;
}

sf::Texture &Img::getButtonArrow_t()
{
	return button_arrow_t;
}

sf::Texture &Img::getSettingIco()
{
	return settingIco_t;
}
sf::Texture &Img::getBonus_t()
{
	return bonus_t;
}

void Img::setBoss_t(string name) {
	boss_t.loadFromFile(name.c_str());
}
void Img::setEnemy_t(string name) {
	enemy_t.loadFromFile(name.c_str());
}
void Img::setSpaceship_t(string name) {
	spaceship_t.loadFromFile(name.c_str());
}

sf::Texture & Img::getAuthors_t() {
	return this->authors_t;
}
sf::Texture &Img::getAbout_t() {
	return this->about_t;
}

Img::~Img() {}