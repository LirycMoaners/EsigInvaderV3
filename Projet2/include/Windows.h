#pragma once
#include <SFML/Graphics.hpp>
#include <string>

/// d�finit la f�netre par d�faut
class Windows
{
	public:
		Windows();
		Windows(int width, int height, std::string nameWindows);
		~Windows();
		void setWidth(int);
		void setHeight(int);
		void setTitle(std::string);

		//methode de lancement de la f�netre
		virtual void runWindows() = 0;

	protected:
		//largeur
		int width;
		//hauteur
		int height;
		//titre
		std::string title;
		//f�netre courante
		sf::RenderWindow *window;
};

