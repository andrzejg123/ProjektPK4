#pragma once
#include "Moveable.h"

class RandomMoveHelper
{
	float maxDistance = 500.0f;
	float currentTimeToWait = -1.0f;
	int maxTimeToWait = 15;
	sf::Vector2u changeDirectionChance = sf::Vector2u{ 1, 6 };
	sf::Vector2u waitChance = sf::Vector2u{2, 5 };
	Moveable* movable;
	Direction lastDirection;
	sf::Vector2f lastPosition;
	sf::Vector2f startPosition;
	static Direction getRandomDirection();
	Direction checkNewDirection(sf::Time& elapsedTime);
	Direction handleWait(const sf::Time& time);
public:
	Direction getDirection(sf::Time& elapsedTime);
	explicit RandomMoveHelper(Moveable* movable);
};

