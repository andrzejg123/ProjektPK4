#pragma once
#include "GameMap.h"
#include <list>
#include <fstream>
#include "EnemyParams.h"

class FileReadingController
{
	std::ifstream file;
public:
	MapDrawingData* loadMapDrawingData(MapIndicator mapIndicator);
	MapGameplayData* loadMapGameplayData(MapIndicator mapIndicator, sf::Vector2u tileSize);
	std::list<sf::FloatRect>* loadCollisionRects(MapIndicator dataIndicator);

	EnemyParamsFactors loadEnemyParamsFactors(ObjectIndicator enemyIndicator);

	FileReadingController();
	~FileReadingController();
};

