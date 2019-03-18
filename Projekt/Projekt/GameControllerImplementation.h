#pragma once
#include "GameView.h"
#include "GameController.h"
#include "GameMapController.h"
#include "GameTexturesHolder.h"
#include "GameObjectHolder.h"
#include "GameEnemyController.h"

class GameControllerImplementation : public GameController
{
	GameView* gameView;
	GameMapController* gameMapController;
	GameTexturesHolder* gameTexturesHolder;
	GameObjectHolder* gameObjectsHolder;
	GameEnemyController* gameEnemyController;

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
	explicit GameControllerImplementation(GameView* gameView);
	~GameControllerImplementation();
};

