#pragma once
#include "Damageable.h"
#include "Player.h"
#include "GameObjectsController.h"
#include "GameTexturesHolder.h"
#include "RandomMoveController.h"

class Enemy : public Moveable, public Animated, public Damageable
{
	int attackCounter = 0;
	RandomMoveController* randomMoveHelper;
protected:
	bool sawPlayer = false; // if marked as true enemy will follow player until his death
	float visionRadius = 0.0f;
	float attackRadius = 0.0f;
	int attackSpeed = 100;
	//Performs attack on player
	virtual void attack(Player* player, GameObjectsController* gameObjectsController, GameTexturesHolder* gameTexturesHolder) = 0;
public:
	//Checking if should attack, follow player or move and doing so
	void performAction(Player* player, GameObjectsController* gameObjectsController, GameTexturesHolder* gameTexturesHolder);
	Enemy();
	virtual ~Enemy();
};

