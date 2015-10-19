#include "..\include\GameWindows.h"
using namespace tinyxml2;
void GameWindows::loadData(Img* img) {
	XMLDocument doc;
	XMLError e = doc.LoadFile("conf/conf.xml");
	if (e == XML_NO_ERROR) {
		XMLNode * root = doc.RootElement();
		XMLElement * elementLevels = root->FirstChildElement("Levels");
		XMLElement * elementEnemies = root->FirstChildElement("Enemies");
		XMLElement * elementBosses = root->FirstChildElement("Bosses");
		if (elementLevels != NULL && elementEnemies != NULL && elementBosses != NULL) {
			XMLElement * elementLevel = elementLevels->FirstChildElement("Level");
			XMLElement * elementEnemy = elementEnemies->FirstChildElement("Enemy");
			XMLElement * elementBoss = elementBosses->FirstChildElement("Boss");
			do {
				if (elementLevel != NULL && elementEnemy != NULL && elementBoss != NULL) {
					XMLElement * elementNbEnemy = elementLevel->FirstChildElement("NbEnemy");
					XMLElement * elementUrl = elementLevel->FirstChildElement("UrlImageBackground");
					XMLElement * elementSpeed = elementLevel->FirstChildElement("SpeedEnemyFire");
					int nb = 0,speed = 0, life = 0, dommage = 0, sizeEscouad  = 0,lifeBoss = 0,dommageBoss =0;
					string url;
					if (elementNbEnemy != NULL) {
						nb = atoi(elementNbEnemy->GetText());
					}
					if (elementUrl != NULL) {
						url = elementUrl->GetText();
					}
					if (elementSpeed != NULL) {
						speed = atoi(elementSpeed->GetText());
					}
					XMLElement * elementLife = elementEnemy->FirstChildElement("Life");
					XMLElement * elementDommage = elementEnemy->FirstChildElement("Dommage");
					XMLElement * elementSizeEscouade = elementEnemy->FirstChildElement("SizeEscouade");
					if (elementLife != NULL) {
						life = atoi(elementLife->GetText());
					}
					if (elementDommage != NULL) {
						dommage = atoi(elementDommage->GetText());
					}
					if (elementSizeEscouade != NULL) {
						sizeEscouad = atoi(elementSizeEscouade->GetText());
					}
					XMLElement * elementLifeBoss = elementBoss->FirstChildElement("Life");
					XMLElement * elementDommageBoss = elementBoss->FirstChildElement("Dommage");
					if (elementLifeBoss != NULL) {
						lifeBoss = atoi(elementLifeBoss->GetText());
					}
					if (elementDommageBoss != NULL) {
						dommageBoss = atoi(elementDommageBoss->GetText());
					}
					Boss * b = new Boss(lifeBoss, dommageBoss, img->getEnemy_t());
					TypeEnemy * type = new TypeEnemy(life, dommage, sizeEscouad);
					Level * l = new Level(nb, speed, type, b, url);
					this->levels.push_back(l);
					elementLevel = elementLevel->NextSiblingElement("Level");
					elementEnemy = elementEnemy->NextSiblingElement("Enemy");
					elementBoss = elementBoss->NextSiblingElement("Boss");
				}
			} while (elementLevel != NULL && elementEnemy != NULL && elementBoss != NULL);
		}
		cout <<"Nb Level Loaded : " <<this->levels.size() << endl;
		
		//cout << "Nb Level Loaded : " << << endl;
	}
	
}

GameWindows::GameWindows(int w, int h, string name, bool available) : Windows(w, h, name,available) {
	Img* img = new Img();
	this->loadData(img);
	this->field = new Field(available,img);
	Level * l = this->levels.at(0);
}

void GameWindows::runWindows() {
	while (this->window->isOpen() && this->field->getSpaceship()->isAlive())
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
			field->getSpaceship()->switchFps();
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
		this->window->draw(field->getSpaceship()->getSprite());

		for (int i = 0; i < field->getEnemies().size(); i++)
		{
			field->getEnemies().at(i)->move();
			window->draw((field->getEnemies().at(i))->getSprite());
		}

		this->window->display();
	}
}