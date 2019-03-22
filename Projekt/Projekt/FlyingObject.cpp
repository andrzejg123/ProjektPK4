#include "stdafx.h"
#include "FlyingObject.h"

void FlyingObject::move(Direction direction, sf::Time& elapsedTime)
{
	Moveable::move(xFactor, yFactor, elapsedTime);
}

FlyingObject::FlyingObject(const float xFactor, const float yFactor): xFactor(xFactor), yFactor(yFactor)
{
}
