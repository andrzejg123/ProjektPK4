#include "stdafx.h"
#include "FileReadingController.h"


MapData* FileReadingController::loadMapData(MapDataIndicator dataIndicator)
{
	auto data = new MapData;
	file.open("maps/map_" + std::to_string(int(dataIndicator)) + ".txt");
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
	file.close();
	return data;
}

std::list<sf::FloatRect>* FileReadingController::loadCollisionRects(MapDataIndicator dataIndicator)
{
	auto collisionRects = new std::list<sf::FloatRect>;
	file.open("maps/map_collisions_" + std::to_string(int(dataIndicator)) + ".txt");
	if(file.good())
	{
		float top, left, width, height;
		while (!file.eof())
		{
			file >> left;
			file >> top;
			file >> width;
			file >> height;
			collisionRects->emplace_back(left, top, width, height);
		}
	}
	return collisionRects;
}

FileReadingController::FileReadingController()
= default;


FileReadingController::~FileReadingController()
= default;
