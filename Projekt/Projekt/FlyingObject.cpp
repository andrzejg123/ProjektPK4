#include "stdafx.h"
#include "FlyingObject.h"

void FlyingObject::move(Direction direction)
{
	Moveable::move(xFactor, yFactor);
}

FlyingObject::FlyingObject(const float xFactor, const float yFactor): xFactor(xFactor), yFactor(yFactor)
{
}
