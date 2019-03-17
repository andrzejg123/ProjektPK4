#include "stdafx.h"
#include "Moveable.h"

void Moveable::move(const Direction direction)
{
	moveX = 0.0;
	moveY = 0.0;
	const auto horizontal = 0.707107f; // sqrt(2) / 2
	switch(direction)
	{
	case Direction::Up:
		moveY = -speed;
		break;
	case Direction::UpLeft:
		moveX = -speed * horizontal;
		moveY = -speed * horizontal;
		break;
	case Direction::Left:
		moveX = -speed;
		break;
	case Direction::DownLeft:
		moveX = -speed * horizontal;
		moveY = speed * horizontal;
		break;
	case Direction::Down:
		moveY = speed;
		break;
	case Direction::DownRight:
		moveX = speed * horizontal;
		moveY = speed * horizontal;
		break;
	case Direction::Right:
		moveX = speed;
		break;
	case Direction::UpRight:
		moveX = speed * horizontal;
		moveY = -speed * horizontal;
		break;
	case Direction::None: break;
	default: ;
	}
	sprite.move(moveX, moveY);
}

void Moveable::move(const float xFactor, const float yFactor)
{
	moveX = speed * xFactor;
	moveY = speed * yFactor;
	sprite.move(moveX, moveY);
}

void Moveable::cancelMove()
{
	sprite.move(-moveX, -moveY);
}

void Moveable::setSpeed(const float speed)
{
	this->speed = speed;
}

Moveable::Moveable()
{
}


Moveable::~Moveable()
{
}
