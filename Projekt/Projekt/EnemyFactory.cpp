#include "stdafx.h"
#include "EnemyFactory.h"
#include "WildDog.h"

Enemy* EnemyFactory::create(const TextureIndicator textureIndicator) const
{
	const auto enemyParams = EnemyParams::Builder(1)
		.setPosition(rand() % 512, rand() % 256)
		.multiplyVisionRadiusByValue(1.0f)
		.multiplyArmorByValue(0.75f)
		.multiplyHealthByValue(1.25f)
		.setAttackRadius(70.0f)
		.multiplySpeedByValue(1.0f)
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
