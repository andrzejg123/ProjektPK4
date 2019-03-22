#pragma once
#include "GameEnemyController.h"
#include "GameTexturesHolder.h"

class GameEnemyControllerImplementation : public GameEnemyController
{
	GameObjectsHolder* gameObjectsHolder;
	GameTexturesHolder* gameTexturesHolder;
	void handleAttack(Enemy* enemy) const;
public:
	void updateEnemy(sf::Time& elapsedTime, Enemy* enemy) override;
	GameEnemyControllerImplementation(GameObjectHolder* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder);
	~GameEnemyControllerImplementation();
};

