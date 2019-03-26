#include "stdafx.h"
#include "MathHelper.h"
#include <cmath>
#include <valarray>
#include <complex>

float MathHelper::getDistance(const sf::Vector2f vector1, const sf::Vector2f vector2)
{
	const auto vector = vector1 - vector2;
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

Direction MathHelper::getDirection(const sf::Vector2f fromVector, const sf::Vector2f toVector)
{
	const auto vector = fromVector - toVector;
	const auto tan = abs(std::atan2(vector.y, vector.x) * 180.0f / 3.14f - 180.0f);
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

float MathHelper::getAngle(const Direction direction)
{
	switch (direction) { 
		case Direction::Up: return 90.0f;
		case Direction::Left: return 180.0f;
		case Direction::Down: return 270.0f;
		case Direction::Right: return 0.0f;
		case Direction::UpLeft: return 135.0f;
		case Direction::DownLeft: return 225.0f;
		case Direction::DownRight: return 315.0f;
		case Direction::UpRight: return 45.0f;
		case Direction::None: return 0.0f;
		default: return 0.0f;
	}
}

sf::Vector2f MathHelper::getFactor(const sf::Vector2f fromVector, sf::Vector2f toVector)
{
	const auto c = getDistance(fromVector, toVector);
	toVector -= fromVector;
	toVector.y /= c;
	toVector.x /= c;
	return toVector;
}

Facing MathHelper::directionToFacing(const Facing oldFacing, Direction newDirection)
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
	case  Direction::None:
		return oldFacing;
	default: return Facing(newDirection);
	}
	return oldFacing;
}

Direction MathHelper::getOppositeDirection(const Direction direction)
{
	switch (direction) { 
		case Direction::Up: return Direction::Down;
		case Direction::Left: return Direction::Right;
		case Direction::Down: return Direction::Up;
		case Direction::Right: return Direction::Left;
		case Direction::UpLeft: return Direction::DownRight;
		case Direction::DownLeft: return Direction::UpRight;
		case Direction::DownRight:return Direction::UpLeft;
		case Direction::UpRight: return Direction::DownLeft;
		case Direction::None: return Direction::None;
	default: return Direction::None;
	}
}

float MathHelper::getRotation(const float xFactor, const float yFactor, const Direction sourceTextureDirection)
{
	return std::abs(std::atan2(xFactor, yFactor) * (180.0f / 3.14f) - 90.0f - getAngle(sourceTextureDirection));
}
