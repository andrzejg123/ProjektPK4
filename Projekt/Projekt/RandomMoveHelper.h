#pragma once
#include "Enemy.h"

class RandomMoveControllerImplementation
{
	Enemy* enemy;
	Direction lastDirection;
	sf::Vector2f lastPosition;
	static Direction getRandomDirection();
	static bool rollRandom(int from, int to);
public:
	Direction getDirection();
	explicit RandomMoveControllerImplementation(Enemy* enemy);
	~RandomMoveControllerImplementation();
};

