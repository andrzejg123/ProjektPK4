#include "stdafx.h"
#include "RandomMoveControllerImplementation.h"
#include <time.h>
#include "Log.h"

Direction RandomMoveControllerImplementation::getRandomDirection()
{
	return static_cast<Direction>(rand() % 8);
}

bool RandomMoveControllerImplementation::rollRandom(const int from, const int to)
{
	return from > (rand() % to);
}

Direction RandomMoveControllerImplementation::getDirection()
{
	if(lastPosition != movable->getPosition())
	{
		lastPosition = movable->getPosition();
		if (rollRandom(1, 100))
			lastDirection = getRandomDirection();
	} else
		lastDirection = getRandomDirection();
	return lastDirection;
}

RandomMoveControllerImplementation::RandomMoveControllerImplementation(Moveable* movable)
{
	this->movable = movable;
	lastDirection = getRandomDirection();
	lastPosition = this->movable->getPosition();
}
