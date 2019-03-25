#pragma once
#include "FlyingObject.h"
#include "GameObjectsHolder.h"
#include "TexturesHolder.h"

class FlyingObjectFactory
{
	TexturesHolder* texturesHolder;
public:
	//Creates flyingObject according to texture indicator
	FlyingObject* create(Enemy* caster, Object* destination, ObjectIndicator objectIndicator) const;
	explicit FlyingObjectFactory(TexturesHolder* texturesHolder);
	~FlyingObjectFactory();
};

