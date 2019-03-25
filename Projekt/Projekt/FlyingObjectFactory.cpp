#include "stdafx.h"
#include "FlyingObjectFactory.h"
#include "DistanceHelper.h"
#include "Enemy.h"
#include "Arrow.h"
#include "TexturesHolder.h"
#include "SoundController.h"

FlyingObject* FlyingObjectFactory::create(Enemy* caster, Object* destination, const ObjectIndicator objectIndicator) const
{
	const auto factor = DistanceHelper::getFactor(caster->getPosition(), destination->getPosition());
	switch (objectIndicator)
	{
		case ObjectIndicator::PlayerWarrior:
			return new Arrow(texturesHolder->getTexture(objectIndicator), caster, factor);
		default:
			return new Arrow(texturesHolder->getTexture(objectIndicator), caster, factor);
	}
}

FlyingObjectFactory::FlyingObjectFactory(TexturesHolder* texturesHolder)
{
	this->texturesHolder = texturesHolder;
}

FlyingObjectFactory::~FlyingObjectFactory()
{
}
