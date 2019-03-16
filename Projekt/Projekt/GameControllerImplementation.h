#pragma once
#include "GameView.h"
#include "GameController.h"
#include "GameMapController.h"
#include "GameTexturesHolder.h"
#include "Player.h"

class GameControllerImplementation : public GameController
{
	GameView* gameView;
	GameMapController* gameMapController;
	GameTexturesHolder* gameTexturesHolder;
	Player *player = nullptr;

public:
	void getFirstLayer() override;
	//Loads the map and the objects
	void initializeGame() override;
	Player* getPlayer() override;
	void movePlayer(Direction direction) override;
	void stopPlayer() override;
	void updateGame(const sf::Time& elapsed) override;
	GameMap* getMap() override;
	GameControllerImplementation(GameView* gameView);
	~GameControllerImplementation();
};

