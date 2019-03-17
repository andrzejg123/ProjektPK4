#include "stdafx.h"
#include "GameControllerImplementation.h"
#include "WildDog.h"
#include "DistanceHelper.h"
#include "SoundController.h"
#include "GameObjectsControllerImplementation.h"
#include "EnemyFactory.h"

void GameControllerImplementation::getFirstLayer()
{
	return;
}

void GameControllerImplementation::initializeGame()
{
	SoundController::getInstance()->playMusic(MusicIndicator::DEFAULT);
	gameMapController->loadMap(MapDataIndicator::Test);
	gameObjectsController->setPlayer(new Player(gameTexturesHolder->getTexture(TextureIndicator::PlayerWarrior)));
	gameObjectsController->addEnemy(EnemyFactory(gameTexturesHolder).create(TextureIndicator::PlayerWarrior));
}

void GameControllerImplementation::movePlayer(const Direction direction)
{
	auto player = gameObjectsController->getPlayer();
	player->move(direction);
	for (auto enemy : *gameObjectsController->getEnemies())
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
	gameObjectsController->getPlayer()->stopAnimate(AnimationType::Move);
}

void GameControllerImplementation::updateFlyingObjects(const sf::Time& elapsedTime) const
{
	auto list = *gameObjectsController->getFlyingObjects();
	auto it = list.begin();
	while (it != list.end()) {
		const auto flyingObject = *it;
		flyingObject->move(Direction::None);
		if (gameMapController->checkCollision(flyingObject))
		{
			flyingObject->hit();
			it = list.erase(it);
			gameObjectsController->removeFlyingObject(flyingObject);
		}
		else if (gameObjectsController->getPlayer()->getBounds().intersects(flyingObject->getFixedBounds())) {
			flyingObject->hitDamageable(gameObjectsController->getPlayer());
			it = list.erase(it);
			gameObjectsController->removeFlyingObject(flyingObject);
		}
		else
			++it;
	}
}

void GameControllerImplementation::updateEnemies(const sf::Time& elapsedTime) const
{
	for (auto enemy : *gameObjectsController->getEnemies())
	{
		enemy->performAction(gameObjectsController->getPlayer(), gameObjectsController, gameTexturesHolder);
		if (gameMapController->checkCollision(enemy))
			enemy->cancelMove();
	}
}

void GameControllerImplementation::updateGame(const sf::Time& elapsed)
{
	updateEnemies(elapsed);
	updateFlyingObjects(elapsed);
	for (auto animated : *gameObjectsController->getAnimatedList())
		animated->updateAnimation(elapsed);
}

GameMap* GameControllerImplementation::getMap()
{
	return gameMapController->getMap();
}

std::list<Object*>* GameControllerImplementation::getObjectsToDraw()
{
	return gameObjectsController->getObjects();
}

GameControllerImplementation::GameControllerImplementation(GameView* gameView): gameView(gameView)
{
	this->gameMapController = new GameMapController();
	this->gameTexturesHolder = new GameTexturesHolder();
	this->gameObjectsController = new GameObjectsControllerImplementation();
}

GameControllerImplementation::~GameControllerImplementation()
{
	delete this->gameMapController;
	delete this->gameTexturesHolder;
	delete this->gameObjectsController;
}
