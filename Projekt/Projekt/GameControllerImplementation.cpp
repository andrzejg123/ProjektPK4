#include "stdafx.h"
#include "GameControllerImplementation.h"
#include "MathHelper.h"
#include "SoundController.h"
#include "EnemyFactory.h"
#include "Warrior.h"
#include "EnemyControllerImplementation.h"
#include "Log.h"
#include "InteractiveFactory.h"
#include "OptionsViewImplementation.h"

void GameControllerImplementation::getFirstLayer()
{
	return;
}

void GameControllerImplementation::initializeGame()
{
	SoundController::getInstance()->playMusic(MusicIndicator::DEFAULT);
	gameMapController->loadMap(MapIndicator::Test2);
	auto gameplayData = gameMapController->getGameplayData();

	//creating enemies
	for(auto spawnArea : gameplayData->spawnAreas)
	{
		const auto entitiesNumber = rand() % (spawnArea.getMaxEntitiesNumber() - spawnArea.getMinEntitiesNumber() + 1) + spawnArea.getMinEntitiesNumber();
		switch(spawnArea.getEntityKind()) 
		{ 
		case EntityKind::Enemy: 
			
			for (auto i = 0; i < entitiesNumber; ++i)
				gameObjectsHolder->addEnemy(EnemyFactory(gameTexturesHolder, gameEntityDataHolder).create(
					spawnArea.getEntityIndicator(), spawnArea.getSpawnAreaRect(), gameplayData->level));
			break;
		case EntityKind::Passive:
			//TODO passive mob factory
			break;
		default: ;
		}
	}

	//creating interactive objects
	for (auto interactiveData : gameplayData->interactivesData)
	{
		gameObjectsHolder->addInteractiveObject(InteractiveFactory(gameTexturesHolder, gameEntityDataHolder).create(interactiveData));
	}

	gameObjectsHolder->setPlayer(new Warrior(gameTexturesHolder->getTexture(ObjectIndicator::PlayerWarrior), gameEntityDataHolder->getAnimationData(ObjectIndicator::PlayerWarrior)));
	gameObjectsHolder->getPlayer()->setPosition(sf::Vector2f(30, 100));
}

void GameControllerImplementation::movePlayer(const Direction direction, sf::Time& elapsedTime)
{
	auto player = gameObjectsHolder->getPlayer();
	if (player->isDead())
		return;
	player->move(direction, elapsedTime);

	for (auto enemy : *gameObjectsHolder->getEnemies())
		if(enemy->getFixedBounds().intersects(player->getFixedBounds()))
			player->cancelMove();

	for (auto interactive : *gameObjectsHolder->getInteractiveList())
		if (interactive->getFixedBounds().intersects(player->getFixedBounds()))
			player->cancelMove();
	
	if (gameMapController->checkCollision(player))
		player->cancelMove();
	player->setFacing(MathHelper::directionToFacing(player->getFacing(), direction));
	player->animate(AnimationType::Move);
	interactionController->checkInteractions();
}

void GameControllerImplementation::stopPlayer()
{
	gameObjectsHolder->getPlayer()->stopAnimate(AnimationType::Move);
}

void GameControllerImplementation::updateFlyingObjects(sf::Time& elapsedTime) const
{
	auto list = *gameObjectsHolder->getFlyingObjects();
	auto it = list.begin();
	while (it != list.end()) {
		const auto flyingObject = *it;
		flyingObject->move(Direction::None, elapsedTime);
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

void GameControllerImplementation::updateGame(sf::Time& elapsed)
{
	for (auto enemy : *gameObjectsHolder->getEnemies())
	{
		gameEnemyController->updateEnemy(elapsed, enemy, pendingActionsController);
		if (gameMapController->checkCollision(enemy))
			enemy->cancelMove();
	}
	updateFlyingObjects(elapsed);
	for (auto animated : *gameObjectsHolder->getAnimatedList())
		animated->updateAnimation(elapsed);

	pendingActionsController->checkPendingActions(elapsed);
}

void GameControllerImplementation::playerInteract()
{
	interactionController->handleInteraction();
}

GameMap* GameControllerImplementation::getMap()
{
	return gameMapController->getMap();
}

std::list<Object*>* GameControllerImplementation::getObjectsToDraw()
{
	return gameObjectsHolder->getObjects();
}

GameObjectsHolder* GameControllerImplementation::getGameObjectHolder()
{
	return this->gameObjectsHolder;
}

std::list<sf::FloatRect>* GameControllerImplementation::getCollisionRects()
{
	return gameMapController->getCollisionRects();
}

GameControllerImplementation::GameControllerImplementation(GameView* gameView): gameView(gameView)
{
	this->fileReadingController = new FileReadingController();
	this->gameMapController = new GameMapController(fileReadingController);
	this->gameTexturesHolder = TexturesHolder::getInstance();
	this->gameObjectsHolder = new GameObjectsHolder();
	this->gameEnemyController = new EnemyControllerImplementation(gameObjectsHolder, gameTexturesHolder);
	this->gameEntityDataHolder = new GameEntityDataHolder(fileReadingController);
	this->pendingActionsController = new PendingActionsController();
	this->interactionController = new GameInteractionController(gameObjectsHolder, gameView, pendingActionsController);
	
}

GameControllerImplementation::~GameControllerImplementation()
{
	delete this->gameMapController;
	delete this->gameObjectsHolder;
	delete this->gameEnemyController;
	delete this->fileReadingController;
	delete this->gameEntityDataHolder;
	delete this->interactionController;
	delete this->pendingActionsController;
}