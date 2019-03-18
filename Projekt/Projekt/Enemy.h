#pragma once
#include "Damageable.h"
#include "Player.h"
#include "GameObjectHolder.h"
#include "GameTexturesHolder.h"
#include "RandomMoveController.h"
#include "EnemyParams.h"

class Enemy : public Moveable, public Animated, public Damageable
{
	int attackCounter = 0;
	RandomMoveController* randomMoveHelper;
protected:
	bool sawPlayer = false; // if marked as true enemy will follow player until his death
	float visionRadius = 60.0f;
	float attackRadius = 50.0f;
	int attackSpeed = 100;
	//Performs attack on player
	virtual void attack(Player* player, GameObjectHolder* gameObjectsController, GameTexturesHolder* gameTexturesHolder) = 0;
public:
	//Checking if should attack, follow player or move and doing so
	void performAction(Player* player, GameObjectHolder* gameObjectsController, GameTexturesHolder* gameTexturesHolder);
	Enemy(EnemyParams* enemyParams);
	virtual ~Enemy();
};

