#include "stdafx.h"
#include "ViewHelper.h"

unsigned ViewHelper::adjustFontSize(const unsigned size, const sf::Vector2u windowSize)
{
	return size + ((windowSize.x + windowSize.y) / 300);
}
