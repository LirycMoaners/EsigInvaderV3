#pragma once
#include <SFML/Graphics.hpp>
#include <string>

/// définit la fênetre par défaut
class Windows
{
	public:
		//Windows()
		Windows();
		//Windows(int width, int height, std::string nameWindows)
		Windows(int width, int height, std::string nameWindows);
		~Windows();
		void setWidth(int);
		void setHeight(int);
		void setTitle(std::string);

		//methode de lancement de la fênetre
		virtual void runWindows() = 0;

	protected:
		//largeur
		int width;
		//hauteur
		int height;
		//titre
		std::string title;
		//fênetre courante
		sf::RenderWindow *window;
};

