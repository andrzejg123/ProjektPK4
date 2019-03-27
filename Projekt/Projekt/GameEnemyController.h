#pragma once
#include "GameObjectsHolder.h"
#include "Enemy.h"
#include "PendingActionsController.h"

class GameEnemyController
{
public:
	virtual ~GameEnemyController() = default;
	virtual void updateEnemy(sf::Time& elapsedTime, Enemy* enemy, PendingActionsController* pendingActionsController) = 0;
};

