#include "stdafx.h"
#include "FlyingObject.h"
#include "Log.h"
#include <valarray>
#include "DistanceHelper.h"

void FlyingObject::move(Direction direction, sf::Time& elapsedTime)
{
	Moveable::move(xFactor, yFactor, elapsedTime);
}

FlyingObject::FlyingObject(const float xFactor, const float yFactor): xFactor(xFactor), yFactor(yFactor)
{
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(DistanceHelper::getRotation(xFactor, yFactor, -90.0f));
}
