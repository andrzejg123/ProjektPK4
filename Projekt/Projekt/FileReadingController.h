#pragma once
#include "GameMap.h"
#include <list>
#include <fstream>

class FileReadingController
{
	std::ifstream file;
public:
	MapData* loadMapData(MapDataIndicator dataIndicator);
	std::list<sf::FloatRect>* loadCollisionRects(MapDataIndicator dataIndicator);
	FileReadingController();
	~FileReadingController();
};

