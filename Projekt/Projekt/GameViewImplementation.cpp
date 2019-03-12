#include "stdafx.h"
#include "GameViewImplementation.h"
#include "GameControllerImplementation.h"
#include <SFML/Graphics.hpp>

GameViewImplementation::GameViewImplementation(): gameController(new GameControllerImplementation(this))
{

}


GameViewImplementation::~GameViewImplementation()
{
}

void GameViewImplementation::displayGame()
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
		//gameController->getAllDrawable();
		window.display();
	}
}
