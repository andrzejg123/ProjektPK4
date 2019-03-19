#include "stdafx.h"
#include "GameEntityDataHolder.h"

EnemyParamsFactors& GameEntityDataHolder::getEnemyParamsFactors(const ObjectIndicator enemyIndicator)
{
	const auto i = enemiesParamsFactors->find(enemyIndicator);
	if (i == enemiesParamsFactors->end())
	{
		auto newEnemyParamsFactors = fileReadingController->loadEnemyParamsFactors(enemyIndicator);
		(*enemiesParamsFactors)[enemyIndicator] = newEnemyParamsFactors;
		return (*enemiesParamsFactors)[enemyIndicator];
	}

	return i->second;
}

GameEntityDataHolder::GameEntityDataHolder(FileReadingController* fileReadingController) : fileReadingController(fileReadingController)
{
	this->enemiesParamsFactors = new std::map<ObjectIndicator, EnemyParamsFactors>;
	this->animationsData = new std::map<ObjectIndicator, AnimationData>;
}

GameEntityDataHolder::~GameEntityDataHolder()
{
	delete this->enemiesParamsFactors;
	delete this->animationsData;
}
