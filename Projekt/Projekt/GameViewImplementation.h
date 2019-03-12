#pragma once
#include "GameController.h"
#include "GameView.h"

class GameViewImplementation: GameView
{
	GameController* gameController;

public:
	void displayGame();
	GameViewImplementation();
	~GameViewImplementation();
};

