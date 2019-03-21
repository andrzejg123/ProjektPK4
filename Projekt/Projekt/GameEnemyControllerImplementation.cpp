#include "stdafx.h"
#include "GameEnemyControllerImplementation.h"
#include "DistanceHelper.h"
#include "RandomMoveControllerImplementation.h"
#include "FlyingObjectFactory.h"

void GameEnemyControllerImplementation::handleAttack(Enemy* enemy) const
{
	const auto data = enemy->getAttackData();
	switch (data.attackType)
	{
	case AttackType::Arrow:
		{
		const auto arrow = FlyingObjectFactory(gameTexturesHolder).create(enemy, gameObjectsHolder->getPlayer(), ObjectIndicator::PlayerWarrior);
		gameObjectsHolder->addFlyingObject(arrow);
		break;
		}
	default: ;
	}
}

void GameEnemyControllerImplementation::updateEnemy(const sf::Time& time, Enemy* enemy)
{
	const auto player = gameObjectsHolder->getPlayer();
	enemy->incrementAttackCounter();
	const auto distance = DistanceHelper::getDistance(player->getPosition(), enemy->getPosition());
	const auto direction = DistanceHelper::getDirection(enemy->getPosition(), player->getPosition());
	if (distance < enemy->getAttackRadius())
	{
		enemy->setSawPlayer();
		if (enemy->getAttackCounter() > enemy->getAttackSpeed())
		{
			enemy->resetAttackCounter();
			handleAttack(enemy);
			enemy->animate(AnimationType::Attack);
			enemy->setFacing(DistanceHelper::directionToFacing(enemy->getFacing(), direction));
		}
		enemy->stopAnimate(AnimationType::Move);
		return;
	}
	if (enemy->didSawPlayer() || distance < enemy->getVisionRadius())
	{
		enemy->setSawPlayer();
		enemy->makeMove(direction);
	}
	else
		enemy->makeRandomMove();
	if (player->getFixedBounds().intersects(enemy->getFixedBounds()))
		enemy->cancelMove();
}

GameEnemyControllerImplementation::GameEnemyControllerImplementation(GameObjectHolder* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder)
{
	this->gameObjectsHolder = gameObjectsHolder;
	this->gameTexturesHolder = gameTexturesHolder;;
}

GameEnemyControllerImplementation::~GameEnemyControllerImplementation()
{
}
