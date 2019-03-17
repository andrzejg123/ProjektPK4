#include "stdafx.h"
#include "EnemyFactory.h"
#include "WildDog.h"

Enemy* EnemyFactory::create(const TextureIndicator textureIndicator) const
{
	switch (textureIndicator)
	{
	case TextureIndicator::PlayerWarrior: 
		return new WildDog(gameTexturesHolder->getTexture(textureIndicator));
	default: 
		return new WildDog(gameTexturesHolder->getTexture(textureIndicator));
	}
}

EnemyFactory::EnemyFactory(GameTexturesHolder* gameTexturesHolder)
{
	this->gameTexturesHolder = gameTexturesHolder;
}

EnemyFactory::~EnemyFactory()
{
}
