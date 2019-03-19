#pragma once
#include "GameView.h"
#include "GameController.h"
#include "GameMapController.h"
#include "GameTexturesHolder.h"
#include "GameObjectHolder.h"
#include "GameEnemyController.h"
#include "GameEntityDataHolder.h"

class GameControllerImplementation : public GameController
{
	GameView* gameView;
	GameMapController* gameMapController;
	GameTexturesHolder* gameTexturesHolder;
	GameObjectHolder* gameObjectsHolder;
	GameEnemyController* gameEnemyController;
	GameEntityDataHolder* gameEntityDataHolder;
	FileReadingController* fileReadingController;

public:
	void getFirstLayer() override;
	//Loads the map and the objects
	void initializeGame() override;
	void movePlayer(Direction direction) override;
	void stopPlayer() override;
	void updateFlyingObjects(const sf::Time& elapsedTime) const;
	void updateGame(const sf::Time& elapsed) override;
	GameMap* getMap() override;
	std::list<Object*>* getObjectsToDraw() override;
	GameObjectHolder* getGameObjectHolder() override;
	std::list<sf::FloatRect>* getCollisionRects() override;
	explicit GameControllerImplementation(GameView* gameView);
	~GameControllerImplementation();
};

