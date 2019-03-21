#include "stdafx.h"
#include "EnemyFactory.h"
#include "RogueArcher.h"

Enemy* EnemyFactory::create(const ObjectIndicator enemyIndicator, sf::FloatRect& spawnAreaRect, const int mapLevel) const
{
	const auto& enemyParamsFactors = gameEntityDataHolder->getEnemyParamsFactors(enemyIndicator);
	const auto enemyLevel = mapLevel + rand() % 3;
	auto& animationData = gameEntityDataHolder->getAnimationData(enemyIndicator);

	const auto enemyPositionX = float(rand() % int((spawnAreaRect.left + spawnAreaRect.width) * 1000 - spawnAreaRect.left * 1000)) / 1000.0 + spawnAreaRect.left;
	const auto enemyPositionY = float(rand() % int((spawnAreaRect.top + spawnAreaRect.height) * 1000 - spawnAreaRect.top * 1000)) / 1000.0 + spawnAreaRect.top;

	//fixing position - so that the fixed bounds center will be placed in randomized position
	const auto positionFixingX = animationData.frameSizeX / 2.0;
	const auto positionFixingY = animationData.frameSizeY - animationData.frameSizeY / 8.4;

	const auto enemyParams = EnemyParams::Builder(enemyLevel)
		.setPosition(enemyPositionX - positionFixingX, enemyPositionY - positionFixingY)
		.multiplyVisionRadiusByValue(enemyParamsFactors.visionRadiusFactor)
		.multiplyArmorByValue(enemyParamsFactors.armorFactor)
		.multiplyHealthByValue(enemyParamsFactors.healthFactor)
		.setAttackRadius(enemyParamsFactors.attackRadiusFactor)
		.multiplySpeedByValue(enemyParamsFactors.speedFactor)
		.build();
	switch (enemyIndicator)
	{
	case ObjectIndicator::RogueArcher: 
		return new RogueArcher(gameTexturesHolder->getTexture(enemyIndicator), enemyParams, animationData);
	default: 
		return new RogueArcher(gameTexturesHolder->getTexture(enemyIndicator), enemyParams, animationData);
	} 
}

EnemyFactory::EnemyFactory(GameTexturesHolder* gameTexturesHolder, GameEntityDataHolder* gameEntityDataHolder)
{
	this->gameTexturesHolder = gameTexturesHolder;
	this->gameEntityDataHolder = gameEntityDataHolder;
}

EnemyFactory::~EnemyFactory()
{
}
