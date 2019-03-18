#include "stdafx.h"
#include "Enemy.h"
#include "DistanceHelper.h"
#include "RandomMoveControllerImplementation.h"
#include "EnemyParams.h"
#include "Log.h"

bool Enemy::didSawPlayer() const
{
	return sawPlayer;
}

void Enemy::setSawPlayer()
{
	sawPlayer = true;
}

float Enemy::getVisionRadius() const
{
	return visionRadius;
}

float Enemy::getAttackRadius() const
{
	return attackRadius;
}

float Enemy::getAttackSpeed() const
{
	return attackSpeed;
}

int Enemy::getAttackCounter() const
{
	return attackCounter;
}

void Enemy::incrementAttackCounter()
{
	attackCounter++;
}

void Enemy::resetAttackCounter()
{
	attackCounter = 0;
}

void Enemy::makeRandomMove()
{
	const auto direction = randomMoveHelper->getDirection();
	makeMove(direction);
}

void Enemy::makeMove(const Direction direction)
{
	move(direction);
	setFacing(DistanceHelper::directionToFacing(this->getFacing(), direction));
	animate(AnimationType::Move);
}

Enemy::Enemy(EnemyParams* enemyParams)
{
	randomMoveHelper = new RandomMoveControllerImplementation(this);
	attackRadius = enemyParams->getAttackRadius();
	visionRadius = enemyParams->getVisionRadius();
	setPosition(sf::Vector2f(enemyParams->getPositionX(), enemyParams->getPositionY()));
	setSpeed(enemyParams->getSpeed());
	delete enemyParams;
}

Enemy::~Enemy()
{
	delete randomMoveHelper;
}
