#include "stdafx.h"
#include "RandomMoveHelper.h"
#include "Log.h"
#include "MathHelper.h"
#include "RandomHelper.h"
#include <ctime>

Direction RandomMoveHelper::getRandomDirection()
{
	return Direction(RandomHelper::getRandomInt(8));
}

Direction RandomMoveHelper::handleWait(const sf::Time& time)
{
	currentTimeToWait -= time.asSeconds();
	return Direction::None;
}

Direction RandomMoveHelper::checkNewDirection(sf::Time& elapsedTime)
{
	lastPosition = movable->getPosition();
	if (RandomHelper::rollRandom(changeDirectionChance.x, static_cast<unsigned>(changeDirectionChance.y / elapsedTime.asSeconds())))
	{
		Log::debugS("changed direction");
		return getRandomDirection();
	}
	if (RandomHelper::rollRandom(waitChance.x, static_cast<unsigned>(waitChance.y / elapsedTime.asSeconds())))
	{
		Log::debugS("waiting");
		currentTimeToWait = static_cast<float>(RandomHelper::getRandomInt(maxTimeToWait));
		return Direction::None;
	}
	if (maxDistance < MathHelper::getDistance(lastPosition, startPosition))
	{
		//Log::debugS("coming back to spawn");
		return MathHelper::getDirection(lastPosition, startPosition);
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
