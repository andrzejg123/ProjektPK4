#include "stdafx.h"
#include "EnemyFactory.h"
#include "WildDog.h"

Enemy* EnemyFactory::create(const TextureIndicator textureIndicator) const
{
	const auto enemyParams = EnemyParams::Builder()
	.setPosition(60,70)
	.setSpeed(4.0f)
	.build();
	switch (textureIndicator)
	{
	case TextureIndicator::PlayerWarrior: 
		return new WildDog(gameTexturesHolder->getTexture(textureIndicator), enemyParams);
	default: 
		return new WildDog(gameTexturesHolder->getTexture(textureIndicator), enemyParams);
	}
}

EnemyFactory::EnemyFactory(GameTexturesHolder* gameTexturesHolder)
{
	this->gameTexturesHolder = gameTexturesHolder;
}

EnemyFactory::~EnemyFactory()
{
}
