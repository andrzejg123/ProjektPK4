#pragma once
#include "GameEnemyController.h"
#include "TexturesHolder.h"

class GameEnemyControllerImplementation : public GameEnemyController
{
	GameObjectsHolder* gameObjectsHolder;
	TexturesHolder* gameTexturesHolder;
	void handleAttack(Enemy* enemy) const;
public:
	void updateEnemy(sf::Time& elapsedTime, Enemy* enemy) override;
	GameEnemyControllerImplementation(GameObjectsHolder* gameObjectsHolder, TexturesHolder* gameTexturesHolder);
	~GameEnemyControllerImplementation();
};

