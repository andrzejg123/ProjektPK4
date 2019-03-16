#include "stdafx.h"
#include "WildDog.h"
#include "GameObjectsHolder.h"
#include "DistanceHelper.h"
#include "Arrow.h"
#include "GameTexturesHolder.h"
#include <iostream>
#include "Log.h"

// todo problem with class gameObjectsHolder
void WildDog::attack(Player* player, void* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder)
{
	Log::debugS("wild dog attack");
	const auto factor = DistanceHelper::getFactor(this->getPosition(), player->getPosition());
	static_cast<GameObjectsHolder*>(gameObjectsHolder)->addFlyingObject(new Arrow(gameTexturesHolder->getTexture(TextureIndicator::PlayerWarrior), this, factor));
}

WildDog::WildDog(sf::Texture& wildDogTexture) : Object(wildDogTexture)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * 64, 64, 64));
	sprite.setPosition(120, 70);
	setSpeed(0.5);
}


WildDog::~WildDog()
{
}
