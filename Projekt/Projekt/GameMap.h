#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "spawnAreaRect.h"
#include <list>
#include "Interactive.h"

enum class MapIndicator
{
	Test,
	Test2
};

enum class MapTileSetIndicator
{
	StandardForest
};

struct MapDrawingData
{
	MapTileSetIndicator tileSetIndicator;
	sf::Vector2u tileSize;
	unsigned int width;
	unsigned int height;
	std::vector<int> firstLayerTiles;
	std::vector<int> secondLayerTiles;

};

struct MapGameplayData
{
	int level;
	std::list<SpawnArea> spawnAreas;
	std::list<InteractiveData> interactivesData;
};

class GameMap : public sf::Drawable
{
	sf::VertexArray firstLayerVertices; //for background
	sf::VertexArray secondLayerVertices; //for half-transparent objects placed over background (trees etc.)
	sf::Texture tileSet; 
	MapTileSetIndicator tileSetIndicator; //for checking if there is a need to reload tile set

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
public:
	void load(MapDrawingData &mapData);
	GameMap();
	~GameMap();
};

