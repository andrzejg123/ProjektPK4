#pragma once
#include "FlyingObject.h"
#include "GameObjectsController.h"
#include "GameTexturesHolder.h"

class FlyingObjectFactory
{
	GameTexturesHolder* gameTexturesHolder;
public:
	FlyingObject* create(Enemy* caster, Object* destination, TextureIndicator textureIndicator) const;
	FlyingObjectFactory(GameTexturesHolder* gameTexturesHolder);
	~FlyingObjectFactory();
};

