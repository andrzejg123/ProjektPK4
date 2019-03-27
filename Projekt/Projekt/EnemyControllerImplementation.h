#pragma once
#include "EnemyController.h"
#include "TexturesHolder.h"
#include "PendingActionsController.h"

class EnemyControllerImplementation : public EnemyController
{
	GameObjectsHolder* gameObjectsHolder;
	TexturesHolder* gameTexturesHolder;
	void handleAttack(Enemy* enemy) const;
public:
	void updateEnemy(sf::Time& elapsedTime, Enemy* enemy, PendingActionsController* pendingActionsController) override;
	EnemyControllerImplementation(GameObjectsHolder* gameObjectsHolder, TexturesHolder* gameTexturesHolder);
	~EnemyControllerImplementation();
};

