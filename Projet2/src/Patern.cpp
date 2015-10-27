#include "Patern.h"
#include <string>

Patern::Patern()
{
}

Patern::Patern(tinyxml2::XMLDocument &docPat, int id) : time(0)
{
	bool read = false;
	tinyxml2::XMLHandle hdl(&docPat);
	patern = hdl.FirstChildElement().FirstChildElement().ToElement();
	while (read == false && patern){
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

vector<Enemy*> Patern::spawn(sf::Texture &t)
{
	vector<Enemy*> e;
	sf::Vector2f pos;
	string position;
	tinyxml2::XMLElement *l = patern->FirstChildElement();

	while (l)
	{
		if (l->FirstChildElement()->GetText() == to_string(time))
		{

			position = l->FirstChildElement()->NextSiblingElement()->GetText();
			for (int i = 0; i < 7; i++)
			{
				if (position.substr(i, 1) == to_string(1))
					e.push_back(new Enemy(t, sf::Vector2f(1024, 100 * i), lvlEnemy, typeEnemy));
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
