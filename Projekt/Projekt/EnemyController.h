#pragma once
#include "GameObjectsHolder.h"
#include "PendingActionsController.h"

class EnemyController
{
public:
	virtual ~EnemyController() = default;
	virtual void updateEnemy(sf::Time& elapsedTime, Enemy* enemy, PendingActionsController* pendingActionsController) = 0;
};

