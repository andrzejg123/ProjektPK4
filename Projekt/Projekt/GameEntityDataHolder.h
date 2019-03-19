#pragma once
#include "FileReadingController.h"
#include "Animated.h"

class GameEntityDataHolder
{
	std::map<ObjectIndicator, EnemyParamsFactors>* enemiesParamsFactors;
	std::map<ObjectIndicator, AnimationData>* animationsData;
	FileReadingController* fileReadingController;

public:
	EnemyParamsFactors& getEnemyParamsFactors(ObjectIndicator enemyIndicator);
	AnimationData& getAnimationData(ObjectIndicator entityIndicator);
	GameEntityDataHolder(FileReadingController* fileReadingController);
	~GameEntityDataHolder();
};

