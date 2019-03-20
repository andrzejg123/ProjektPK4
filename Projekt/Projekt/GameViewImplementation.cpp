#include "stdafx.h"
#include "GameViewImplementation.h"
#include "GameControllerImplementation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Keys.h"

GameViewImplementation::GameViewImplementation(sf::RenderWindow* window)
{
	this->gameController = new GameControllerImplementation(this);
	this->window = window;
	this->debugDrawer = new DebugDrawer();
}

GameViewImplementation::~GameViewImplementation()
{
	delete this->gameController;
	delete this->debugDrawer;
}

void GameViewImplementation::displayGame() const
{
	gameController->initializeGame();
	auto& window = *this->window;

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
			if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::F3)
			{
				if (Keys::projectType != ProjectType::Release)
					debugDrawer->toggle();
			}
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
		for (auto objectToDraw : *gameController->getObjectsToDraw())
			window.draw(*objectToDraw);

		debugDrawer->draw(gameController->getCollisionRects(), gameController->getGameObjectHolder(), &window);

		window.display();
	}

}
