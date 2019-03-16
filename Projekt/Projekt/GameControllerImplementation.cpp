#include "stdafx.h"
#include "GameControllerImplementation.h"
#include "WildDog.h"
#include "DistanceHelper.h"
#include <iostream>
#include "SoundController.h"

void GameControllerImplementation::getFirstLayer()
{
	return;
}

void GameControllerImplementation::initializeGame()
{
	SoundController::getInstance()->playMusic(MusicIndicator::DEFAULT);
	gameMapController->loadMap(MapDataIndicator::Test);
	auto& playerTexture = gameTexturesHolder->getTexture(TextureIndicator::PlayerWarrior);
	gameObjectsHolder->setPlayer(new Player(playerTexture));
	gameObjectsHolder->addEnemy(new WildDog(playerTexture));
}

void GameControllerImplementation::movePlayer(const Direction direction)
{
	auto player = gameObjectsHolder->getPlayer();
	player->move(direction);
	for (auto enemy : *gameObjectsHolder->getEnemies())
	{
		if(enemy->getFixedBounds().intersects(player->getFixedBounds()))
			player->cancelMove();
	}
	if (gameMapController->checkCollision(player))
		player->cancelMove();
	player->setFacing(DistanceHelper::directionToFacing(player->getFacing(), direction));
	player->animate(AnimationType::Move);
}

void GameControllerImplementation::stopPlayer()
{
	gameObjectsHolder->getPlayer()->stopAnimate(AnimationType::Move);
}

void GameControllerImplementation::updateFlyingObjects(const sf::Time& elapsedTime) const
{
	auto list = *gameObjectsHolder->getFlyingObjects();
	auto it = list.begin();
	while (it != list.end()) {
		const auto flyingObject = *it;
		flyingObject->move(Direction::None);
		if (gameMapController->checkCollision(flyingObject))
		{
			it = list.erase(it);
			gameObjectsHolder->removeFlyingObject(flyingObject);
		}
		else if (gameObjectsHolder->getPlayer()->getBounds().intersects(flyingObject->getFixedBounds())) {
			it = list.erase(it);
			gameObjectsHolder->removeFlyingObject(flyingObject);
		}
		else
			++it;
	}
}

void GameControllerImplementation::updateEnemies(const sf::Time& elapsedTime) const
{
	for (auto enemy : *gameObjectsHolder->getEnemies())
	{
		enemy->performAction(gameObjectsHolder->getPlayer(), gameObjectsHolder, gameTexturesHolder);
		if (gameMapController->checkCollision(enemy))
			enemy->cancelMove();
	}
}

void GameControllerImplementation::updateGame(const sf::Time& elapsed)
{
	updateEnemies(elapsed);
	updateFlyingObjects(elapsed);
	for (auto animated : *gameObjectsHolder->getAnimatedList())
		animated->updateAnimation(elapsed);
}

GameMap* GameControllerImplementation::getMap()
{
	return gameMapController->getMap();
}

std::list<Object*>* GameControllerImplementation::getObjectsToDraw()
{
	return gameObjectsHolder->getObjects();
}

GameControllerImplementation::GameControllerImplementation(GameView* gameView): gameView(gameView)
{
	this->gameMapController = new GameMapController();
	this->gameTexturesHolder = new GameTexturesHolder();
	this->gameObjectsHolder = new GameObjectsHolder();
}

GameControllerImplementation::~GameControllerImplementation()
{
	delete this->gameMapController;
	delete this->gameTexturesHolder;
	delete this->gameObjectsHolder;
}
