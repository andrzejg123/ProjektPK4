#include "stdafx.h"
#include "GameEnemyControllerImplementation.h"
#include "MathHelper.h"
#include "FlyingObjectFactory.h"

void GameEnemyControllerImplementation::handleAttack(Enemy* enemy) const
{
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

void GameEnemyControllerImplementation::updateEnemy(sf::Time& elapsedTime, Enemy* enemy)
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
			handleAttack(enemy);
			enemy->animate(AnimationType::Attack);
			enemy->setFacing(MathHelper::directionToFacing(enemy->getFacing(), direction));
		}
		enemy->stopAnimate(AnimationType::Move);
		return;
	}
	if (enemy->didSawPlayer() || distance < enemy->getVisionRadius())
	{
		enemy->setSawPlayer();
		enemy->makeMove(direction, elapsedTime);
	}
	else
		enemy->makeRandomMove(elapsedTime);
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
