#pragma once
#include "GameController.h"
#include "GameView.h"
#include "DebugDrawer.h"

class GameViewImplementation: GameView
{
	GameController* gameController;
	DebugDrawer* debugDrawer;

public:
	void displayGame() const;
	GameViewImplementation();
	~GameViewImplementation();
};

