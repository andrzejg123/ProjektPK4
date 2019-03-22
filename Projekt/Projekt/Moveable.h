#pragma once
#include "Object.h"
#include <SFML/System/Time.hpp>

//Predefined directions for moving player
enum class Direction
{
	Up,
	Left,
	Down,
	Right,
	UpLeft,
	DownLeft,
	DownRight,
	UpRight,
	None
};

class Moveable : public virtual Object
{
	float speed = 60.0;
	float moveX = 0, moveY = 0;

public:
	//Move in a predefined direction
	virtual void move(Direction direction, sf::Time& elapsedTime);

	//Move in more specified direction
	void move(float xFactor, float yFactor, sf::Time& elapsedTime);

	//When collision
	void cancelMove();

	//Sets speed
	void setSpeed(float speed);

	Moveable();
	~Moveable();
};

