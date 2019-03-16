#include "stdafx.h"
#include "GameMap.h"

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = &tileSet;
	target.draw(firstLayerVertices, states);
	target.draw(secondLayerVertices, states);
}

void GameMap::load(MapData& mapData)
{
	if(this->tileSetIndicator != mapData.tileSetIndicator)
	{
		this->tileSetIndicator = mapData.tileSetIndicator;
		tileSet.loadFromFile("maps/tilesets/tileset_" + std::to_string(int(this->tileSetIndicator)) + ".png");
	}
	
	// resize the vertex array to fit the level size
	firstLayerVertices.setPrimitiveType(sf::Quads);
	firstLayerVertices.resize(mapData.width * mapData.height * 4);
	secondLayerVertices.setPrimitiveType(sf::Quads);
	secondLayerVertices.resize(mapData.width * mapData.height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < mapData.width; ++i)
		for (unsigned int j = 0; j < mapData.height; ++j)
		{
			// get the current tile number
			const auto tileNumber = mapData.firstLayerTiles[i + j * mapData.width];
			const auto tileNumber2 = mapData.secondLayerTiles[i + j * mapData.width];

			// find its position in the tileset texture
			const int tu = tileNumber % (tileSet.getSize().x / mapData.tileSize.x);
			const int tv = tileNumber / (tileSet.getSize().x / mapData.tileSize.x);
			const int tu2 = tileNumber2 % (tileSet.getSize().x / mapData.tileSize.x);
			const int tv2 = tileNumber2 / (tileSet.getSize().x / mapData.tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &firstLayerVertices[(i + j * mapData.width) * 4];
			sf::Vertex* quad2 = &secondLayerVertices[(i + j * mapData.width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * mapData.tileSize.x, j * mapData.tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * mapData.tileSize.x, j * mapData.tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * mapData.tileSize.x, (j + 1) * mapData.tileSize.y);
			quad[3].position = sf::Vector2f(i * mapData.tileSize.x, (j + 1) * mapData.tileSize.y);
			quad2[0].position = sf::Vector2f(i * mapData.tileSize.x, j * mapData.tileSize.y);
			quad2[1].position = sf::Vector2f((i + 1) * mapData.tileSize.x, j * mapData.tileSize.y);
			quad2[2].position = sf::Vector2f((i + 1) * mapData.tileSize.x, (j + 1) * mapData.tileSize.y);
			quad2[3].position = sf::Vector2f(i * mapData.tileSize.x, (j + 1) * mapData.tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * mapData.tileSize.x, tv * mapData.tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * mapData.tileSize.x, tv * mapData.tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * mapData.tileSize.x, (tv + 1) * mapData.tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * mapData.tileSize.x, (tv + 1) * mapData.tileSize.y);
			quad2[0].texCoords = sf::Vector2f(tu2 * mapData.tileSize.x, tv2 * mapData.tileSize.y);
			quad2[1].texCoords = sf::Vector2f((tu2 + 1) * mapData.tileSize.x, tv2 * mapData.tileSize.y);
			quad2[2].texCoords = sf::Vector2f((tu2 + 1) * mapData.tileSize.x, (tv2 + 1) * mapData.tileSize.y);
			quad2[3].texCoords = sf::Vector2f(tu2 * mapData.tileSize.x, (tv2 + 1) * mapData.tileSize.y);
		}

}

GameMap::GameMap()
{
	
}


GameMap::~GameMap()
{
}
