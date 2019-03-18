#pragma once
#include "GameObjectHolder.h"
#include "Enemy.h"

class GameEnemyController
{
public:
	virtual ~GameEnemyController() = default;
	virtual void updateEnemy(const sf::Time& time, Enemy* enemy) = 0;
};

