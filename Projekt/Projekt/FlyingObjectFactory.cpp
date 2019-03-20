#include "stdafx.h"
#include "FlyingObjectFactory.h"
#include "DistanceHelper.h"
#include "Enemy.h"
#include "Arrow.h"
#include "GameTexturesHolder.h"
#include "SoundController.h"

FlyingObject* FlyingObjectFactory::create(Enemy* caster, Object* destination, const ObjectIndicator textureIndicator) const
{
	const auto factor = DistanceHelper::getFactor(caster->getPosition(), destination->getPosition());
	switch (textureIndicator)
	{
		case ObjectIndicator::PlayerWarrior:
			return new Arrow(gameTexturesHolder->getTexture(textureIndicator), caster, factor);
		default:
			return new Arrow(gameTexturesHolder->getTexture(textureIndicator), caster, factor);
	}
}

FlyingObjectFactory::FlyingObjectFactory(GameTexturesHolder* gameTexturesHolder)
{
	this->gameTexturesHolder = gameTexturesHolder;
}

FlyingObjectFactory::~FlyingObjectFactory()
{
}
