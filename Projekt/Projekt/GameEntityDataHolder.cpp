#include "stdafx.h"
#include "GameEntityDataHolder.h"

std::map<std::string, float>& GameEntityDataHolder::getEnemyParamsFactors(const ObjectIndicator enemyIndicator) const
{
	const auto i = enemiesParamsFactors->find(enemyIndicator);
	if (i == enemiesParamsFactors->end())
	{
		const auto newEnemyParamsFactors = fileReadingController->loadEnemyParamsFactors(enemyIndicator);
		(*enemiesParamsFactors)[enemyIndicator] = newEnemyParamsFactors;
		return (*enemiesParamsFactors)[enemyIndicator];
	}

	return i->second;
}

AnimationData& GameEntityDataHolder::getAnimationData(const ObjectIndicator entityIndicator) const
{
	const auto i = animationsData->find(entityIndicator);
	if (i == animationsData->end())
	{
		const auto newAnimationData = fileReadingController->loadAnimationData(entityIndicator);
		(*animationsData)[entityIndicator] = newAnimationData;
		return (*animationsData)[entityIndicator];
	}

	return i->second;
}

GameEntityDataHolder::GameEntityDataHolder(FileReadingController* fileReadingController) : fileReadingController(fileReadingController)
{
	this->enemiesParamsFactors = new std::map<ObjectIndicator, std::map<std::string, float>>;
	this->animationsData = new std::map<ObjectIndicator, AnimationData>;
}

GameEntityDataHolder::~GameEntityDataHolder()
{
	delete this->enemiesParamsFactors;
	delete this->animationsData;
}
