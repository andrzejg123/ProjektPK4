#pragma once
#include "TexturesHolder.h"
#include "Enemy.h"
#include "GameEntityDataHolder.h"

class EnemyFactory
{
	TexturesHolder* gameTexturesHolder;
	GameEntityDataHolder* gameEntityDataHolder;
public:
	//Creates enemy according to texture indicator
	Enemy* create(ObjectIndicator objectIndicator, sf::FloatRect& spawnAreaRect, int mapLevel) const;
	explicit EnemyFactory(TexturesHolder* gameTexturesHolder, GameEntityDataHolder* gameEntityDataHolder);
	~EnemyFactory();
};

