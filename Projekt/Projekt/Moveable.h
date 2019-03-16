#pragma once
#include "Object.h"

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
	UpRight
};

class Moveable : public virtual Object
{
	float speed = 1.0;
	float moveX, moveY;

public:
	//Move in a predefined direction
	void move(Direction direction);

	//When collision
	void cancelMove();

	Moveable();
	~Moveable();
};

