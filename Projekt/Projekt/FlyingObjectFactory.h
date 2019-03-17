#pragma once
#include "FlyingObject.h"
#include "GameObjectsController.h"
#include "GameTexturesHolder.h"

class FlyingObjectFactory
{
	GameTexturesHolder* gameTexturesHolder;
public:
	//Creates flyingObject according to texture indicator
	FlyingObject* create(Enemy* caster, Object* destination, TextureIndicator textureIndicator) const;
	explicit FlyingObjectFactory(GameTexturesHolder* gameTexturesHolder);
	~FlyingObjectFactory();
};

