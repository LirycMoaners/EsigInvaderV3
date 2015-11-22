#include "Patern.h"
#include <string>

using namespace std;
Patern::Patern()
{
}

Patern::Patern(tinyxml2::XMLDocument &docPat, int id) : time(0)
{
	bool read = false;
	tinyxml2::XMLHandle hdl(&docPat);
	patern = hdl.FirstChildElement().FirstChildElement("patern").ToElement();
	if (patern != NULL) {
		while (read == false && patern) {
			if (patern->Attribute("id") == to_string(id))
			{
				typeEnemy = stoi(patern->Attribute("typeEnemy"));
				lvlEnemy = stoi(patern->Attribute("lvlEnemy"));
				duree = stoi(patern->Attribute("duree"));
				patern = patern->FirstChildElement();
				read = true;
			}
			else
				patern = patern->NextSiblingElement();
		}
	}
}

vector<Enemy*> Patern::spawn(Resources &res, TypeEnemy * typeenemy, bool pony, int displayEnemies,int height, int width)
{
	vector<Enemy*> e;
	sf::Vector2f pos;
	string position;
	tinyxml2::XMLElement *l = patern->FirstChildElement();

	while (l)
	{
		if (l->FirstChildElement()->GetText() == to_string(time))
		{
			int randomTExture = rand() % 4;
			position = l->FirstChildElement()->NextSiblingElement()->GetText();
			for (int i = 0; i < displayEnemies; i++)
			{
				std::cout << "Print i:" << i << std::endl;
				int k = i % 7;
				if (position.substr(k, 1) == to_string(1))
					e.push_back(new Enemy(res.getImg()->getEnemy_t(),res, sf::Vector2f(1024, 100 * i + height), typeenemy, randomTExture, pony));
			}
		}
		l = l->NextSiblingElement();
	}

	time++;

	return e;
}

int Patern::next()
{
	if (time > duree)
		return 1;
	else
		return 0;
}

Patern::~Patern()
{
}
