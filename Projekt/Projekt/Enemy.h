#pragma once
#include "Damageable.h"
#include "GameObjectsHolder.h"
#include "EnemyParams.h"
#include "RandomMoveHelper.h"

enum class AttackType
{
	Arrow
};

struct AttackData
{
	float damage;
	AttackType attackType;
};

class Enemy : public Moveable, public Animated, public Damageable
{
	float attackCounter = 0.0f;
	RandomMoveHelper* randomMoveHelper;
protected:
	bool sawPlayer = false; // if marked as true enemy will follow player until his death
	float visionRadius;
	float attackRadius;
	float damage = 1;
	float attackSpeed = 2;
	int level;
public:
	bool didSawPlayer() const;
	void setSawPlayer();
	float getVisionRadius() const;
	float getAttackRadius() const;
	float getAttackSpeed() const;
	int getAttackCounter() const;
	void incrementAttackCounter(sf::Time& elapsedTime);
	void resetAttackCounter();
	void makeRandomMove(sf::Time& elapsedTime);
	void makeMove(Direction direction, sf::Time& elapsedTime);
	virtual AttackData getAttackData() = 0;
	explicit Enemy(EnemyParams* enemyParams, AnimationData& animationData);
	virtual ~Enemy();
};

