#include "stdafx.h"
#include "SpawnArea.h"

ObjectIndicator SpawnArea::getEntityIndicator() const
{
	return entityIndicator;
}

EntityKind SpawnArea::getEntityKind() const
{
	return entityKind;
}

int SpawnArea::getMinEntitiesNumber() const
{
	return minEntitiesNumber;
}

int SpawnArea::getMaxEntitiesNumber() const
{
	return maxEntitiesNumber;
}

sf::FloatRect& SpawnArea::getSpawnAreaRect()
{
	return spawnAreaRect;
}

SpawnArea::SpawnArea(const ObjectIndicator entityIndicator, const EntityKind entityKind, const int minEntitiesNumber,
                     const int maxEntitiesNumber, const sf::FloatRect spawnAreaRect) : entityIndicator(entityIndicator), 
					 entityKind(entityKind), minEntitiesNumber(minEntitiesNumber), maxEntitiesNumber(maxEntitiesNumber),
					 spawnAreaRect(spawnAreaRect) {}

SpawnArea::~SpawnArea()
= default;
