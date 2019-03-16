#pragma once
#include "Damageable.h"
#include "Player.h"
#include "GameObjectsHolder.h"

class GameTexturesHolder;

class Enemy : public Moveable, public Animated, public Damageable
{
	int attackCounter = 0;
protected:
	bool sawPlayer = false; // if marked as true enemy will follow player until his death
	float visionRadius = 110.0f;
	float attackRadius = 100.0f;
	int attackSpeed = 100;
	//Performs attack on player
	virtual void attack(Player* player, void* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder) = 0;
public:
	//Checking if should attack, follow player or move and doing so
	void performAction(Player* player, void* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder);
};

