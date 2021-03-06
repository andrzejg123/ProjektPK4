#include "stdafx.h"
#include "FlyingObject.h"
#include "Log.h"
#include "MathHelper.h"

void FlyingObject::move(Direction direction, sf::Time& elapsedTime)
{
	Moveable::move(xFactor, yFactor, elapsedTime);
}

FlyingObject::FlyingObject(const float xFactor, const float yFactor, Damage& damage, const Direction imageDirection)
{
	this->damage = damage;
	this->xFactor = xFactor;
	this->yFactor = yFactor;
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(MathHelper::getRotation(xFactor, yFactor, imageDirection));
}
