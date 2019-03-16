#include "stdafx.h"
#include "GameViewImplementation.h"
#include "GameControllerImplementation.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameViewImplementation::GameViewImplementation(): gameController(new GameControllerImplementation(this))
{

}

GameViewImplementation::~GameViewImplementation()
{
	delete this->gameController;
}

void GameViewImplementation::displayGame()
{
	sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	gameController->initializeGame();

	sf::Time elapsed;
	sf::Clock gameClock;
	
	while (window.isOpen())
	{
		elapsed = gameClock.restart();
		// handle events
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				gameController->movePlayer(Direction::UpLeft);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
				gameController->movePlayer(Direction::UpRight);
			else
				gameController->movePlayer(Direction::Up);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				gameController->movePlayer(Direction::DownLeft);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
				gameController->movePlayer(Direction::DownRight);
			else
				gameController->movePlayer(Direction::Down);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			gameController->movePlayer(Direction::Left);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			gameController->movePlayer(Direction::Right);
		else
			gameController->stopPlayer();

		gameController->updateGame(elapsed);

		// draw the map
		window.clear();
		window.draw(*gameController->getMap());
		window.draw(*gameController->getPlayer());
		//gameController->getAllDrawable();
		window.display();
	}

}
