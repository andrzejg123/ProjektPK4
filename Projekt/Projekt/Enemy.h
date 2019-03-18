#pragma once
#include "Damageable.h"
#include "Player.h"
#include "GameObjectHolder.h"
#include "GameTexturesHolder.h"
#include "RandomMoveController.h"
#include "EnemyParams.h"

enum class AttackType
{
	Arrow
};

class Enemy : public Moveable, public Animated, public Damageable
{
	int attackCounter = 0;
	RandomMoveController* randomMoveHelper;
protected:
	bool sawPlayer = false; // if marked as true enemy will follow player until his death
	float visionRadius;
	float attackRadius;
	int attackSpeed = 100;
public:
	bool didSawPlayer() const;
	void setSawPlayer();
	float getVisionRadius() const;
	float getAttackRadius() const;
	float getAttackSpeed() const;
	int getAttackCounter() const;
	void incrementAttackCounter();
	void resetAttackCounter();
	void makeRandomMove(Player* player);
	void makeMove(Player* player, Direction direction);
	virtual AttackType getAttackType() = 0;
	explicit Enemy(EnemyParams* enemyParams);
	virtual ~Enemy();
};

