#pragma once
#include "RandomMoveController.h"

class RandomMoveControllerImplementation: public RandomMoveController
{
	Moveable* movable;
	Direction lastDirection;
	sf::Vector2f lastPosition;
	static Direction getRandomDirection();
	static bool rollRandom(int from, int to);
public:
	Direction getDirection() override;
	explicit RandomMoveControllerImplementation(Moveable* movable);
};

