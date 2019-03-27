#pragma once
#include "Damageable.h"
#include "GameObjectsHolder.h"
#include "EnemyParams.h"
#include "RandomMoveHelper.h"
#include "PendingObjectEvent.h"

enum class AttackType
{
	Arrow
};

struct AttackData
{
	Damage damage;
	AttackType attackType;
};

class Enemy : public Moveable, public Animated, public Damageable
{
	float attackCounter = -1.0f;
	RandomMoveHelper* randomMoveHelper;
	PendingObjectEvent* pendingAction = nullptr;
protected:
	bool sawPlayer = false; // if marked as true enemy will follow player until his death
	float visionRadius;
	float attackRadius;
	float attackSpeed;
	Damage damage;
	int level;
public:
	void setPendingAction(PendingObjectEvent* pendingAction);
	bool hasPendingAction() const;
	bool didSawPlayer() const;
	void setSawPlayer();
	float getVisionRadius() const;
	float getAttackRadius() const;
	float getAttackSpeed() const;
	float getAttackCounter() const;
	void incrementAttackCounter(sf::Time& elapsedTime);
	void resetAttackCounter();
	void makeRandomMove(sf::Time& elapsedTime);
	void makeMove(Direction direction, sf::Time& elapsedTime);
	virtual AttackData getAttackData() = 0;
	explicit Enemy(EnemyParams& enemyParams, AnimationData& animationData);
	virtual ~Enemy();
};

