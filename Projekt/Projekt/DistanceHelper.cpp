#include "stdafx.h"
#include "DistanceHelper.h"
#include <cmath>
#include <valarray>
#include <complex>
#include <iostream>

float DistanceHelper::getDistance(const sf::Vector2f vector1, const sf::Vector2f vector2)
{
	const auto vector = vector1 - vector2;
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

Direction DistanceHelper::getDirection(const sf::Vector2f fromVector, const sf::Vector2f toVector)
{
	const auto vector = fromVector - toVector;
	const auto tan = abs(std::atan2(vector.y, vector.x) * 180 / 3.14 - 180.0f);
	if (tan >= 22.5f && tan <= 67.5f)
		return Direction::UpRight;
	if (tan >= 67.5f && tan <= 112.5f)
		return Direction::Up;
	if (tan >= 112.5f && tan <= 157.5f)
		return Direction::UpLeft;
	if (tan >= 157.5f && tan <= 202.5f)
		return Direction::Left;
	if (tan >= 202.5f && tan <= 247.5f)
		return Direction::DownLeft;
	if (tan >= 247.5f && tan <= 292.5f)
		return Direction::Down;
	if (tan >= 292.5f && tan <= 337.5f)
		return Direction::DownRight;
	return Direction::Right;
}

sf::Vector2f DistanceHelper::getFactor(const sf::Vector2f fromVector, sf::Vector2f toVector)
{
	const auto c = getDistance(fromVector, toVector);
	toVector -= fromVector;
	toVector.y /= c;
	toVector.x /= c;
	return toVector;
}

Facing DistanceHelper::directionToFacing(const Facing oldFacing, Direction newDirection)
{
	switch (newDirection)
	{
	case Direction::UpLeft:
		if (oldFacing != Facing::Left)
			return Facing::Up;
		break;
	case Direction::DownLeft:
		if (oldFacing != Facing::Left)
			return Facing::Down;
		break;
	case Direction::DownRight:
		if (oldFacing != Facing::Right)
			return Facing::Down;
		break;
	case Direction::UpRight:
		if (oldFacing != Facing::Right)
			return Facing::Up;
		break;
	default: return Facing(newDirection);
	}
	return oldFacing;
}
