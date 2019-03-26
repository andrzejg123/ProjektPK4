#include "stdafx.h"
#include "GameEnemyControllerImplementation.h"
#include "DistanceHelper.h"
#include "FlyingObjectFactory.h"
#include "Log.h"

void GameEnemyControllerImplementation::handleAttack(Enemy* enemy) const
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

void GameEnemyControllerImplementation::updateEnemy(sf::Time& elapsedTime, Enemy* enemy, PendingActionsController* pendingActionsController)
{
	const auto player = gameObjectsHolder->getPlayer();
	enemy->incrementAttackCounter(elapsedTime);
	const auto distance = DistanceHelper::getDistance(player->getPosition(), enemy->getPosition());
	const auto direction = DistanceHelper::getDirection(enemy->getPosition(), player->getPosition());
	if (distance < enemy->getAttackRadius())
	{
		enemy->setSawPlayer();
		if (enemy->getAttackCounter() > enemy->getAttackSpeed())
		{
			enemy->resetAttackCounter();
			const auto boundAction = std::bind(&GameEnemyControllerImplementation::handleAttack, this, enemy);
			Log::debugA("binding action");
			const auto pendingAttack = new PendingAction(boundAction, sf::seconds(enemy->getAnimationDuration(0.9, AnimationType::Attack)));
			enemy->setPendingAction(pendingAttack);
			pendingActionsController->addPendingAction(pendingAttack);
			enemy->animate(AnimationType::Attack);
			enemy->setFacing(DistanceHelper::directionToFacing(enemy->getFacing(), direction));
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

GameEnemyControllerImplementation::GameEnemyControllerImplementation(GameObjectsHolder* gameObjectsHolder, TexturesHolder* gameTexturesHolder)
{
	this->gameObjectsHolder = gameObjectsHolder;
	this->gameTexturesHolder = gameTexturesHolder;;
}

GameEnemyControllerImplementation::~GameEnemyControllerImplementation()
{
}
