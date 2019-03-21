#pragma once
#include "GameTexturesHolder.h"
#include "Enemy.h"
#include "GameEntityDataHolder.h"

class EnemyFactory
{
	GameTexturesHolder* gameTexturesHolder;
	GameEntityDataHolder* gameEntityDataHolder;
public:
	//Creates enemy according to texture indicator
	Enemy* create(ObjectIndicator enemyIndicator, sf::FloatRect& spawnAreaRect, int mapLevel) const;
	explicit EnemyFactory(GameTexturesHolder* gameTexturesHolder, GameEntityDataHolder* gameEntityDataHolder);
	~EnemyFactory();
};

