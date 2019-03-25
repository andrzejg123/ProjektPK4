#pragma once
#include "GameObjectsHolder.h"
#include "GameView.h"

class GameInteractionController
{
	GameObjectsHolder* gameObjectsHolder;
	Interactive* possibleInteractionObject;
	GameView* gameView;
public:
	void checkInteractions();
	GameInteractionController(GameObjectsHolder* gameObjectsHolder, GameView* gameView);
	~GameInteractionController();
	void handleInteraction();
};

