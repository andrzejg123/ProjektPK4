#include "stdafx.h"
#include "RandomHelper.h"
#include <cstdlib>

bool RandomHelper::rollPercent(const float percent)
{
	return rollRandom(static_cast<unsigned>(percent * 100), 10000);
}

bool RandomHelper::rollRandom(const unsigned from, const unsigned to)
{
	return from > getRandomInt(to + 1);
}

unsigned RandomHelper::getRandomInt(const unsigned number)
{
	return rand() % number;
}
