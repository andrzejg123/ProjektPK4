#pragma once
#include "GameObjectsHolder.h"
#include "Enemy.h"

class GameEnemyController
{
public:
	virtual ~GameEnemyController() = default;
	virtual void updateEnemy(sf::Time& elapsedTime, Enemy* enemy) = 0;
};

