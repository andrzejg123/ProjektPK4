#pragma once
#include <SFML/System/Vector2.hpp>
#include "Moveable.h"

class MathHelper
{
public:
	//Returns distance between two points
	static float getDistance(sf::Vector2f vector1, sf::Vector2f vector2);
	//Returns direction from one vector to another
	static Direction getDirection(sf::Vector2f fromVector, sf::Vector2f toVector);
	//Returns angle from direction
	static float getAngle(Direction direction);
	//Returns factor which should object follow to get to destination point
	static sf::Vector2f getFactor(sf::Vector2f fromVector, sf::Vector2f toVector);
	//Converts direction to facing according to old facing and new direction
	static Facing directionToFacing(Facing oldFacing, Direction newDirection);
	//Returns opposite direction
	static Direction getOppositeDirection(Direction direction);
	//Get rotation from direction and source texture direction
	static float getRotation(float xFactor, float yFactor, Direction sourceTextureDirection);
};

