#include "stdafx.h"
#include "RandomMoveHelper.h"
#include "Log.h"
#include "DistanceHelper.h"

Direction RandomMoveHelper::getRandomDirection()
{
	return static_cast<Direction>(rand() % 8);
}

bool RandomMoveHelper::rollRandom(const int from, const int to)
{
	return from > getRandomInt(to + 1);
}

int RandomMoveHelper::getRandomInt(const int number)
{
	return rand() % number;
}

Direction RandomMoveHelper::handleWait(const sf::Time& time)
{
	currentTimeToWait -= time.asSeconds();
	return Direction::None;
}

Direction RandomMoveHelper::checkNewDirection(sf::Time& elapsedTime)
{
	lastPosition = movable->getPosition();
	if (rollRandom(changeDirectionChance.x, changeDirectionChance.y / elapsedTime.asSeconds()))
	{
		Log::debugS("changed direction");
		return getRandomDirection();
	}
	if (rollRandom(waitChance.x, waitChance.y / elapsedTime.asSeconds()))
	{
		Log::debugS("waiting");
		currentTimeToWait = getRandomInt(maxTimeToWait);
		return Direction::None;
	}
	if (maxDistance < DistanceHelper::getDistance(lastPosition, startPosition))
	{
		//Log::debugS("coming back to spawn");
		return DistanceHelper::getDirection(lastPosition, startPosition);
	}
	return lastDirection;
}

Direction RandomMoveHelper::getDirection(sf::Time& elapsedTime)
{
	if (currentTimeToWait > 0)
		return handleWait(elapsedTime);
	if (lastPosition != movable->getPosition())
		lastDirection = checkNewDirection(elapsedTime);
	else
		lastDirection = getRandomDirection();
	return lastDirection;
}

RandomMoveHelper::RandomMoveHelper(Moveable* movable)
{
	this->movable = movable;
	lastDirection = getRandomDirection();
	lastPosition = this->movable->getPosition();
	startPosition = lastPosition;
}
