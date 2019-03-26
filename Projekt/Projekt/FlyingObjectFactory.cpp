#include "stdafx.h"
#include "FlyingObjectFactory.h"
#include "MathHelper.h"
#include "Enemy.h"
#include "Arrow.h"
#include "TexturesHolder.h"
#include "SoundController.h"

FlyingObject* FlyingObjectFactory::create(Enemy* caster, Object* destination, const ObjectIndicator objectIndicator) const
{
	const auto factor = MathHelper::getFactor(caster->getCenter(), destination->getCenter());
	switch (objectIndicator)
	{
		case ObjectIndicator::PlayerWarrior:
			return new Arrow(texturesHolder->getTexture(objectIndicator), caster, factor, caster->getAttackData().damage);
		default:
			return new Arrow(texturesHolder->getTexture(objectIndicator), caster, factor, caster->getAttackData().damage);
	}
}

FlyingObjectFactory::FlyingObjectFactory(TexturesHolder* texturesHolder)
{
	this->texturesHolder = texturesHolder;
}

FlyingObjectFactory::~FlyingObjectFactory()
{
}
