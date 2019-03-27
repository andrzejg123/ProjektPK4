#include "stdafx.h"
#include "EnemyFactory.h"
#include "RogueArcher.h"

Enemy* EnemyFactory::create(const ObjectIndicator objectIndicator, sf::FloatRect& spawnAreaRect, const int mapLevel) const
{
	const auto& enemyParamsFactors = gameEntityDataHolder->getEnemyParamsFactors(objectIndicator);
	const auto enemyLevel = mapLevel + rand() % 3;
	auto& animationData = gameEntityDataHolder->getAnimationData(objectIndicator);

	const auto enemyPositionX = float(rand() % int((spawnAreaRect.left + spawnAreaRect.width) * 1000 - spawnAreaRect.left * 1000)) / 1000.0f + spawnAreaRect.left;
	const auto enemyPositionY = float(rand() % int((spawnAreaRect.top + spawnAreaRect.height) * 1000 - spawnAreaRect.top * 1000)) / 1000.0f + spawnAreaRect.top;

	//fixing position - so that the fixed bounds center will be placed in randomized position
	const auto positionFixingX = animationData.frameSizeX / 2.0f;
	const auto positionFixingY = animationData.frameSizeY - animationData.frameSizeY / 8.4f;
	auto builder = EnemyParams::Builder()
		.addFileEnemyParams(enemyParamsFactors)
		.setLevel(enemyLevel)
		.setRank(Rank::Normal)
		.setPosition(enemyPositionX - positionFixingX, enemyPositionY - positionFixingY);
	switch (objectIndicator)
	{
	case ObjectIndicator::RogueArcher: 
		return new RogueArcher(gameTexturesHolder->getTexture(objectIndicator), builder.setRanged(true).setDamageType(DamageType::Arrow).build(), animationData);
	default: 
		return new RogueArcher(gameTexturesHolder->getTexture(objectIndicator), builder.setRanged(true).setDamageType(DamageType::Quarrel).build(), animationData);
	};
}

EnemyFactory::EnemyFactory(TexturesHolder* gameTexturesHolder, GameEntityDataHolder* gameEntityDataHolder)
{
	this->gameTexturesHolder = gameTexturesHolder;
	this->gameEntityDataHolder = gameEntityDataHolder;
}

EnemyFactory::~EnemyFactory()
{
}
