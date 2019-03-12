#pragma once
#include "GameView.h"
#include "GameController.h"
#include "GameMapController.h"

class GameControllerImplementation : public GameController
{
	GameView* gameView;
	GameMapController* gameMapController;
public:
	void getFirstLayer() override;
	GameControllerImplementation(GameView* gameView);
	~GameControllerImplementation();
};

