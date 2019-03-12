// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		
		// handle events
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();


		}

		// draw the map
		window.clear();
		
		window.display();
	}
    return 0;
}

