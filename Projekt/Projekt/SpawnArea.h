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
	sf::FloatRect spawnAreaRect;
public:
	ObjectIndicator getEntityIndicator() const;
	EntityKind getEntityKind() const;
	int getMinEntitiesNumber() const;
	int getMaxEntitiesNumber() const;
	sf::FloatRect& getSpawnAreaRect();
	SpawnArea(ObjectIndicator entityIndicator, EntityKind entityKind, int minEntitiesNumber, int maxEntitiesNumber, sf::FloatRect spawnArea);
	~SpawnArea();
};

