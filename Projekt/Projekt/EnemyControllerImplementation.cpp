#include "stdafx.h"
#include "EnemyControllerImplementation.h"
#include "MathHelper.h"
#include "FlyingObjectFactory.h"
#include "Log.h"
#include "Enemy.h"

void EnemyControllerImplementation::handleAttack(Enemy* enemy) const
{
	enemy->setPendingAction(nullptr);
	const auto data = enemy->getAttackData();
	switch (data.attackType)
	{
	case AttackType::Arrow:
		{
		const auto arrow = FlyingObjectFactory(gameTexturesHolder).create(enemy, gameObjectsHolder->getPlayer(), ObjectIndicator::Arrow);
		gameObjectsHolder->addFlyingObject(arrow);
		break;
		}
	default: ;
	}
}

void EnemyControllerImplementation::updateEnemy(sf::Time& elapsedTime, Enemy* enemy, PendingActionsController* pendingActionsController)
{
	const auto player = gameObjectsHolder->getPlayer();
	if (player->isDead())
		return;
	enemy->incrementAttackCounter(elapsedTime);
	const auto distance = MathHelper::getDistance(player->getPosition(), enemy->getPosition());
	const auto direction = MathHelper::getDirection(enemy->getPosition(), player->getPosition());
	if (distance < enemy->getAttackRadius())
	{
		enemy->setSawPlayer();
		if (enemy->getAttackCounter() > enemy->getAttackSpeed())
		{
			enemy->resetAttackCounter();
			const auto boundAction = std::bind(&EnemyControllerImplementation::handleAttack, this, enemy);
			Log::debugA("binding action");
			const auto pendingAttack = new PendingAction(boundAction, sf::seconds(enemy->getAnimationDuration(0.9, AnimationType::Attack)));
			enemy->setPendingAction(pendingAttack);
			pendingActionsController->addPendingAction(pendingAttack);
			enemy->animate(AnimationType::Attack);
			enemy->setFacing(MathHelper::directionToFacing(enemy->getFacing(), direction));
		}
		enemy->stopAnimate(AnimationType::Move);
		return;
	}
	if (enemy->didSawPlayer() || distance < enemy->getVisionRadius())
	{
		enemy->setSawPlayer();
		if(!enemy->hasPendingAction())
			enemy->makeMove(direction, elapsedTime);
	}
	else
	{
		if (!enemy->hasPendingAction())
			enemy->makeRandomMove(elapsedTime);
	}
		
	if (player->getFixedBounds().intersects(enemy->getFixedBounds()))
		enemy->cancelMove();
}

EnemyControllerImplementation::EnemyControllerImplementation(GameObjectsHolder* gameObjectsHolder, TexturesHolder* gameTexturesHolder)
{
	this->gameObjectsHolder = gameObjectsHolder;
	this->gameTexturesHolder = gameTexturesHolder;;
}

EnemyControllerImplementation::~EnemyControllerImplementation()
{
}
