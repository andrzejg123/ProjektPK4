#pragma once
#include "FileReadingController.h"
#include "Animated.h"

class GameEntityDataHolder
{
	std::map<ObjectIndicator, std::map<std::string, float>>* enemiesParamsFactors;
	std::map<ObjectIndicator, AnimationData>* animationsData;
	FileReadingController* fileReadingController;

public:
	std::map<std::string, float>& getEnemyParamsFactors(ObjectIndicator enemyIndicator) const;
	AnimationData& getAnimationData(ObjectIndicator entityIndicator) const;
	explicit GameEntityDataHolder(FileReadingController* fileReadingController);
	~GameEntityDataHolder();
};

