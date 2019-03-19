#pragma once
#include "GameTexturesHolder.h"

enum class EntityKind
{
	Enemy,
	Passive
};

class SpawnArea
{
	ObjectIndicator entityIndicator;
	EntityKind entityKind;
	int minEntitiesNumber;
	int maxEntitiesNumber;
	sf::FloatRect spawnArea;
public:
	ObjectIndicator getEntityIndicator() const;
	void setEntityIndicator(ObjectIndicator entityIndicator);
	int getMinEntitiesNumber() const;
	void setMinEntitiesNumber(int minEntitiesNumber);
	int getMaxEntitiesNumber() const;
	void setMaxEntitiesNumber(int maxEntitiesNumber);
	sf::FloatRect getSpawnArea() const;
	void setSpawnArea(const sf::FloatRect& spawnArea);
	SpawnArea(ObjectIndicator entityIndicator, EntityKind entityKind, int minEntitiesNumber, int maxEntitiesNumber, sf::FloatRect spawnArea);
	~SpawnArea();
};

