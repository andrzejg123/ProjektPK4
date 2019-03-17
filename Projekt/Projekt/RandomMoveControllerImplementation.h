#pragma once
#include "Enemy.h"
#include "RandomMoveController.h"

class RandomMoveControllerImplementation: public RandomMoveController
{
	Enemy* enemy;
	Direction lastDirection;
	sf::Vector2f lastPosition;
	static Direction getRandomDirection();
	static bool rollRandom(int from, int to);
public:
	Direction getDirection() override;
	explicit RandomMoveControllerImplementation(Enemy* enemy);
};

