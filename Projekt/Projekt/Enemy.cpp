#include "stdafx.h"
#include "Enemy.h"
#include "MathHelper.h"
#include "RandomMoveHelper.h"
#include "EnemyParams.h"
#include "Log.h"

void Enemy::setPendingAction(PendingObjectEvent* pendingAction)
{
	this->pendingAction = pendingAction;
}

bool Enemy::hasPendingAction() const
{
	return pendingAction != nullptr;
}

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

float Enemy::getAttackCounter() const
{
	return attackCounter;
}

void Enemy::incrementAttackCounter(sf::Time& elapsedTime)
{
	attackCounter += elapsedTime.asSeconds();
}

void Enemy::resetAttackCounter()
{
	attackCounter = 0;
}

void Enemy::makeRandomMove(sf::Time& elapsedTime)
{
	const auto direction = randomMoveHelper->getDirection(elapsedTime);
	if (direction != Direction::None)
		makeMove(direction, elapsedTime);
	else
		stopAnimate(AnimationType::Move);
}

void Enemy::makeMove(const Direction direction, sf::Time& elapsedTime)
{
	move(direction, elapsedTime);
	setFacing(MathHelper::directionToFacing(this->getFacing(), direction));
	animate(AnimationType::Move);
}

Enemy::Enemy(EnemyParams& enemyParams, AnimationData& animationData) : Animated(animationData)
{
	randomMoveHelper = new RandomMoveHelper(this);
	attackRadius = enemyParams.getAttackRadius();
	visionRadius = enemyParams.getVisionRadius();
	setPosition(sf::Vector2f(enemyParams.getPositionX(), enemyParams.getPositionY()));
	setSpeed(enemyParams.getSpeed());
	damage = enemyParams.getDamage();
	defense = enemyParams.getDefense();
	attackSpeed = enemyParams.getAttackSpeed();
	level = enemyParams.getLevel();
}

Enemy::~Enemy()
{
	delete randomMoveHelper;
	if(hasPendingAction())
		pendingAction->cancel();
}
