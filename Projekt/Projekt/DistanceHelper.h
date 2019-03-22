#pragma once
#include <SFML/System/Vector2.hpp>
#include "Moveable.h"

class DistanceHelper
{
public:
	//Returns distance between two points
	static float getDistance(sf::Vector2f vector1, sf::Vector2f vector2);
	//Returns direction from one vector to another
	static Direction getDirection(sf::Vector2f fromVector, sf::Vector2f toVector);
	//Returns factor which should object follow to get to destination point
	static sf::Vector2f getFactor(sf::Vector2f fromVector, sf::Vector2f toVector);
	//Converts direction to facing according to old facing and new direction
	static Facing directionToFacing(Facing oldFacing, Direction newDirection);
	//Returns opposite direction
	static Direction getOppositeDirection(Direction direction);
};

