#pragma once
#include "GameTexturesHolder.h"
#include "Enemy.h"

class EnemyFactory
{
	GameTexturesHolder* gameTexturesHolder;
public:
	//Creates enemy according to texture indicator
	Enemy* create(ObjectIndicator textureIndicator) const;
	explicit EnemyFactory(GameTexturesHolder* gameTexturesHolder);
	~EnemyFactory();
};

