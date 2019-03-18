#include "stdafx.h"
#include "GameControllerImplementation.h"
#include "DistanceHelper.h"
#include "SoundController.h"
#include "GameObjectsHolderImplementation.h"
#include "EnemyFactory.h"
#include "Warrior.h"
#include "GameEnemyControllerImplementation.h"

void GameControllerImplementation::getFirstLayer()
{
	return;
}

void GameControllerImplementation::initializeGame()
{
	SoundController::getInstance()->playMusic(MusicIndicator::DEFAULT);
	gameMapController->loadMap(MapDataIndicator::Test);
	gameObjectsHolder->setPlayer(new Warrior(gameTexturesHolder->getTexture(TextureIndicator::PlayerWarrior)));
	for (auto i = 0; i < 20; i++)
	{
		gameObjectsHolder->addEnemy(EnemyFactory(gameTexturesHolder).create(TextureIndicator::PlayerWarrior));
		gameObjectsHolder->addEnemy(EnemyFactory(gameTexturesHolder).create(TextureIndicator::PlayerWarrior));
	}
	gameObjectsHolder->addEnemy(EnemyFactory(gameTexturesHolder).create(TextureIndicator::PlayerWarrior));
	gameObjectsHolder->addEnemy(EnemyFactory(gameTexturesHolder).create(TextureIndicator::PlayerWarrior));
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
			flyingObject->hit();
			it = list.erase(it);
			gameObjectsHolder->removeFlyingObject(flyingObject);
		}
		else if (gameObjectsHolder->getPlayer()->getBounds().intersects(flyingObject->getFixedBounds())) {
			flyingObject->hitDamageable(gameObjectsHolder->getPlayer());
			it = list.erase(it);
			gameObjectsHolder->removeFlyingObject(flyingObject);
		}
		else
			++it;
	}
}

void GameControllerImplementation::updateGame(const sf::Time& elapsed)
{
	for (auto enemy : *gameObjectsHolder->getEnemies())
	{
		gameEnemyController->updateEnemy(elapsed, enemy);
		if (gameMapController->checkCollision(enemy))
			enemy->cancelMove();
	}
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
	this->gameObjectsHolder = new GameObjectsHolderImplementation();
	this->gameEnemyController = new GameEnemyControllerImplementation(gameObjectsHolder, gameTexturesHolder);
}

GameControllerImplementation::~GameControllerImplementation()
{
	delete this->gameMapController;
	delete this->gameTexturesHolder;
	delete this->gameObjectsHolder;
	delete this->gameEnemyController;
}
