#pragma once
#include "GameView.h"
#include "GameController.h"
#include "GameMapController.h"
#include "TexturesHolder.h"
#include "GameObjectsHolder.h"
#include "EnemyController.h"
#include "GameEntityDataHolder.h"
#include "OptionsView.h"
#include "GameInteractionController.h"
#include "PendingActionsController.h"

class GameControllerImplementation : public GameController
{
	GameView* gameView;
	GameMapController* gameMapController;
	TexturesHolder* gameTexturesHolder;
	GameObjectsHolder* gameObjectsHolder;
	EnemyController* gameEnemyController;
	GameEntityDataHolder* gameEntityDataHolder;
	FileReadingController* fileReadingController;
	GameInteractionController* interactionController;
	PendingActionsController* pendingActionsController;

public:
	void getFirstLayer() override;
	//Loads the map and the objects
	void initializeGame() override;
	void movePlayer(Direction direction, sf::Time& elapsedTime) override;
	void stopPlayer() override;
	void updateFlyingObjects(sf::Time& elapsedTime) const;
	void updateGame(sf::Time& elapsed) override;
	void playerInteract() override;
	GameMap* getMap() override;
	std::list<Object*>* getObjectsToDraw() override;
	GameObjectsHolder* getGameObjectHolder() override;
	std::list<sf::FloatRect>* getCollisionRects() override;
	explicit GameControllerImplementation(GameView* gameView);
	~GameControllerImplementation();
};

