#include "stdafx.h"
#include "GameViewImplementation.h"
#include "GameControllerImplementation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Keys.h"
#include "DistanceHelper.h"

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
	//TODO camera
	/*sf::View camera;
	camera.setSize(window.getSize().x, window.getSize().y);
	camera.setCenter(camera.getSize().x / 2.0, camera.getSize().y / 2.0);
	const auto cameraMovingFactorX = 0.45 * camera.getSize().x;
	const auto cameraMovingFactorY = 0.45 * camera.getSize().y;*/
	
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

		const auto oldPlayerPosition = gameController->getGameObjectHolder()->getPlayer()->getPosition();
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
		const auto newPlayerPosition = gameController->getGameObjectHolder()->getPlayer()->getPosition();

		gameController->updateGame(elapsed);

		// draw the map
		window.clear();
		window.draw(*gameController->getMap());
		for (auto objectToDraw : *gameController->getObjectsToDraw())
			window.draw(*objectToDraw);

		debugDrawer->draw(gameController->getCollisionRects(), gameController->getGameObjectHolder(), &window);

		//TODO camera
		/*const auto playerDisplacement = newPlayerPosition - oldPlayerPosition;

		if(playerDisplacement.x > 0.0 || playerDisplacement.y > 0.0)
		{
			if (newPlayerPosition.x > camera.getCenter().x + cameraMovingFactorX || newPlayerPosition.y > camera.getCenter().y + cameraMovingFactorY ||
				newPlayerPosition.x < camera.getCenter().x - cameraMovingFactorX || newPlayerPosition.y > camera.getCenter().y - cameraMovingFactorY)
					camera.move(playerDisplacement);

			const auto cameraLeft = camera.getCenter().x - camera.getSize().x / 2.0;
			const auto cameraTop = camera.getCenter().y - camera.getSize().y / 2.0;
			const auto cameraRight = camera.getCenter().x + camera.getSize().x / 2.0;
			const auto cameraBottom = camera.getCenter().y + camera.getSize().y / 2.0;
			if (cameraLeft < 0.0 || cameraTop < 0.0 || cameraRight > 1024.0 || cameraBottom > 512.0)
				camera.move(-playerDisplacement);
		}
		
		
		window.setView(camera);*/
		window.display();
	}
	
}
