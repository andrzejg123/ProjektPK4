#pragma once
#include "GameObjectsHolder.h"
#include "GameView.h"
#include "PendingActionsController.h"

class GameInteractionController
{
	GameObjectsHolder* gameObjectsHolder;
	Interactive* possibleInteractionObject;
	PendingActionsController* pendingActionsController;
	GameView* gameView;
public:
	void checkInteractions();
	GameInteractionController(GameObjectsHolder* gameObjectsHolder, GameView* gameView, PendingActionsController* pendingActionsController);
	~GameInteractionController();
	void handleInteraction();
};

