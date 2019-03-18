#pragma once
#include "GameEnemyController.h"

class GameEnemyControllerImplementation : public GameEnemyController
{
	GameObjectHolder* gameObjectsHolder;
	GameTexturesHolder* gameTexturesHolder;
	void handleAttack(Enemy* enemy) const;
public:
	void updateEnemy(const sf::Time& time, Enemy* enemy) override;
	GameEnemyControllerImplementation(GameObjectHolder* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder);
	~GameEnemyControllerImplementation();
};

