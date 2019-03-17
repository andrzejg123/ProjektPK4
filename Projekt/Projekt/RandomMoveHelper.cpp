#include "stdafx.h"
#include "RandomMoveControllerImplementation.h"
#include <time.h>

Direction RandomMoveControllerImplementation::getRandomDirection()
{
	return static_cast<Direction>(rand() % 8);
}

bool RandomMoveControllerImplementation::rollRandom(const int from, const int to)
{
	return from < (rand() % to);
}

Direction RandomMoveControllerImplementation::getDirection()
{
	if(lastPosition != enemy->getPosition())
	{
		lastPosition = enemy->getPosition();
		if (rollRandom(1, 100))
			lastDirection = getRandomDirection();
	} else
		lastDirection = getRandomDirection();
	return lastDirection;
}

RandomMoveControllerImplementation::RandomMoveControllerImplementation(Enemy* enemy)
{
	this->enemy = enemy;
	lastDirection = getRandomDirection();
	lastPosition = enemy->getPosition();
	srand(time(nullptr));
}

RandomMoveControllerImplementation::~RandomMoveControllerImplementation()
{
}
