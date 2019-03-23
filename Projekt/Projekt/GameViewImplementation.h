#pragma once
#include "GameController.h"
#include "GameView.h"
#include "DebugDrawer.h"
#include "OptionsView.h"
#include "GameViewCloseCallback.h"
#include "View.h"

class GameViewImplementation: public GameView, public GameViewCloseCallback, public View
{
	GameController* gameController;
	DebugDrawer* debugDrawer;
	sf::RenderWindow* window;
	bool shouldShowWindow = true;

public:
	void closeGame() override;
	void show() override;
	sf::Vector2u getWindowSize() override;
	explicit GameViewImplementation(sf::RenderWindow* window);
	~GameViewImplementation();
};

