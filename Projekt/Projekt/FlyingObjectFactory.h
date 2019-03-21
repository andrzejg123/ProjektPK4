#pragma once
#include "FlyingObject.h"
#include "GameObjectsHolder.h"
#include "GameTexturesHolder.h"

class FlyingObjectFactory
{
	GameTexturesHolder* gameTexturesHolder;
public:
	//Creates flyingObject according to texture indicator
	FlyingObject* create(Enemy* caster, Object* destination, ObjectIndicator textureIndicator) const;
	explicit FlyingObjectFactory(GameTexturesHolder* gameTexturesHolder);
	~FlyingObjectFactory();
};

