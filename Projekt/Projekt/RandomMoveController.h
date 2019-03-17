#pragma once
#include "Moveable.h"

class RandomMoveController
{
public:
	virtual Direction getDirection() = 0;
	virtual ~RandomMoveController() = default;
};

