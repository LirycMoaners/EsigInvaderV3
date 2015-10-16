#include "..\include\GameWindows.h"



void GameWindows::setAvalaible(bool avai) {
	this->avalaible = avai;
	this->field = new Field(this->avalaible);
}

GameWindows::GameWindows(int w, int h, string name, bool available) : Windows(w, h, name,available) {
	this->field = new Field(available);
	
	
}

void GameWindows::endInit() {
	//this->window->create(sf::VideoMode(1024, 800), this->title);
	
}

void GameWindows::runWindows() {
	while (this->window->isOpen())
	{
		sf::Event event;
		while (this->window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window->close();
		}

		field->collision(window);
		field->control();

		if (fpsCount >= fpsSwitch)
		{
			field->getSpaceship().switchFps();
			for (int i = 0; i < field->getBullets().size(); i++)
			{
				field->getBullets().at(i)->switchFps();
			}
			fpsCount = 0;
		}
		else
			fpsCount += clk.restart().asMilliseconds();

		this->window->clear();
		for (int i = 0; i < field->getBullets().size(); i++)
		{
			field->getBullets().at(i)->move();
			this->window->draw(field->getBullets().at(i)->getSprite());
		}
		this->window->draw(field->getSpaceship().getSprite());

		for (int i = 0; i < field->getEnemies().size(); i++)
		{
			field->getEnemies().at(i)->move();
			window->draw((field->getEnemies().at(i))->getShape());
		}

		this->window->display();
	}
}