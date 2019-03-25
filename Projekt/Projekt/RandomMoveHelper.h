#pragma once
#include "Moveable.h"

class RandomMoveHelper
{
	float maxDistance = 500.0f;
	float currentTimeToWait = -1.0f;
	int maxTimeToWait = 15;
	sf::Vector2i changeDirectionChance = sf::Vector2i{ 1, 6 };
	sf::Vector2i waitChance = sf::Vector2i{2, 5 };
	Moveable* movable;
	Direction lastDirection;
	sf::Vector2f lastPosition;
	sf::Vector2f startPosition;
	static Direction getRandomDirection();
	Direction checkNewDirection(sf::Time& elapsedTime);
	static bool rollRandom(int from, int to);
	static int getRandomInt(int number);
	Direction handleWait(const sf::Time& time);
public:
	Direction getDirection(sf::Time& elapsedTime);
	explicit RandomMoveHelper(Moveable* movable);
};

