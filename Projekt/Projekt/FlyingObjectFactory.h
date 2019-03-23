#pragma once
#include "FlyingObject.h"
#include "GameObjectsHolder.h"
#include "TexturesHolder.h"

class FlyingObjectFactory
{
	TexturesHolder* gameTexturesHolder;
public:
	//Creates flyingObject according to texture indicator
	FlyingObject* create(Enemy* caster, Object* destination, ObjectIndicator textureIndicator) const;
	explicit FlyingObjectFactory(TexturesHolder* gameTexturesHolder);
	~FlyingObjectFactory();
};

