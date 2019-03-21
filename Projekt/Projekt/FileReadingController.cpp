#include "stdafx.h"
#include "FileReadingController.h"
#include "Log.h"


MapDrawingData* FileReadingController::loadMapDrawingData(MapIndicator mapIndicator)
{
	auto data = new MapDrawingData;
	file.open("maps/map_" + std::to_string(int(mapIndicator)) + ".txt");
	if (file.good())
	{
		int temp, temp2;
		file >> temp;
		data->tileSetIndicator = MapTileSetIndicator(temp);
		file >> temp;
		file >> temp2;
		data->tileSize = sf::Vector2u(temp, temp2);
		file >> data->width;
		file >> data->height;
		data->firstLayerTiles.resize(data->width * data->height);
		data->secondLayerTiles.resize(data->width * data->height);

		for (auto i = 0; i < data->height; ++i)
			for (auto j = 0; j < data->width; ++j)
			{
				file >> data->firstLayerTiles[j + i * data->width];
				file.get();
			}

		for (auto i = 0; i < data->height; ++i)
			for (auto j = 0; j < data->width; ++j)
			{
				file >> data->secondLayerTiles[j + i * data->width];
				file.get();
			}

	}
	//file.clear();
	file.close();
	return data;
}

MapGameplayData* FileReadingController::loadMapGameplayData(MapIndicator mapIndicator, const sf::Vector2u tileSize)
{
	auto data = new MapGameplayData;
	file.open("maps/map_content_" + std::to_string(int(mapIndicator)) + ".txt");
	if(file.good())
	{
		file >> data->level;
		int spawnAreasNumber;
		file >> spawnAreasNumber;
		int minEntitiesNumber, maxEntitiesNumber, temp;
		float spawnAreaTilesLeft, spawnAreaTilesTop, spawnAreaTilesWidth, spawnAreaTilesHeight;
		for(auto i = 0; i < spawnAreasNumber; ++i)
		{
			file >> temp;
			auto entityIndicator = ObjectIndicator(temp);
			file >> temp;
			auto entityKind = EntityKind(temp);
			file >> minEntitiesNumber;
			file >> maxEntitiesNumber;
			file >> spawnAreaTilesLeft;
			file >> spawnAreaTilesTop;
			file >> spawnAreaTilesWidth;
			file >> spawnAreaTilesHeight;
			data->spawnAreas.emplace_back(entityIndicator, entityKind, minEntitiesNumber, maxEntitiesNumber, 
				sf::FloatRect(spawnAreaTilesLeft * tileSize.x, spawnAreaTilesTop * tileSize.y, spawnAreaTilesWidth * tileSize.x, spawnAreaTilesHeight * tileSize.y));
		}
	}
	file.close();
	return data;
}

std::list<sf::FloatRect>* FileReadingController::loadCollisionRects(MapIndicator dataIndicator)
{
	auto collisionRects = new std::list<sf::FloatRect>;
	file.open("maps/map_collisions_" + std::to_string(int(dataIndicator)) + ".txt");
	if(file.good())
	{
		float tilesTop, tilesLeft, tilesWidth, tilesHeight, tileSizeWidth, tileSizeHeight;
		file >> tileSizeWidth;
		file >> tileSizeHeight;
		while (!file.eof())
		{
			file >> tilesLeft;
			file >> tilesTop;
			file >> tilesWidth;
			file >> tilesHeight;
			collisionRects->emplace_back(tilesLeft * tileSizeWidth, tilesTop * tileSizeHeight, tilesWidth * tileSizeWidth, tilesHeight * tileSizeHeight);
		}
	}
	file.close();
	return collisionRects;
}

EnemyParamsFactors FileReadingController::loadEnemyParamsFactors(ObjectIndicator enemyIndicator)
{
	EnemyParamsFactors enemyParamsFactors;
	file.open("entities/enemies/enemy_" + std::to_string(int(enemyIndicator)) + ".txt");
	if(file.good())
	{
		file >> enemyParamsFactors.visionRadiusFactor;
		file >> enemyParamsFactors.armorFactor;
		file >> enemyParamsFactors.healthFactor;
		file >> enemyParamsFactors.attackRadiusFactor;
		file >> enemyParamsFactors.speedFactor;
	}
	file.close();
	return enemyParamsFactors;
}

AnimationData FileReadingController::loadAnimationData(ObjectIndicator entityIndicator)
{
	AnimationData animationData;
	file.open("entities/animations/entity_animation_" + std::to_string(int(entityIndicator)) + ".txt");
	if(file.good())
	{
		file >> animationData.frameSizeX;
		file >> animationData.frameSizeY;
		int animationTypesNumber;
		file >> animationTypesNumber;
		animationData.animationTypesData.reserve(animationTypesNumber);
		int intervalInMilliseconds;
		int animationFrames;
		for(auto i = 0; i < animationTypesNumber; ++i)
		{
			
			file >> intervalInMilliseconds;
			file >> animationFrames;
			animationData.animationTypesData.emplace_back(intervalInMilliseconds, animationFrames);
			
		}
	}
	file.close();
	return animationData;
}

FileReadingController::FileReadingController()
= default;


FileReadingController::~FileReadingController()
= default;
