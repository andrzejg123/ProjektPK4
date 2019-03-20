#include "stdafx.h"
#include "SpawnArea.h"


ObjectIndicator SpawnArea::getEntityIndicator() const
{
	return entityIndicator;
}

void SpawnArea::setEntityIndicator(ObjectIndicator entityIndicator)
{
	this->entityIndicator = entityIndicator;
}

int SpawnArea::getMinEntitiesNumber() const
{
	return minEntitiesNumber;
}

void SpawnArea::setMinEntitiesNumber(int minEntitiesNumber)
{
	this->minEntitiesNumber = minEntitiesNumber;
}

int SpawnArea::getMaxEntitiesNumber() const
{
	return maxEntitiesNumber;
}

void SpawnArea::setMaxEntitiesNumber(int maxEntitiesNumber)
{
	this->maxEntitiesNumber = maxEntitiesNumber;
}

sf::FloatRect SpawnArea::getSpawnArea() const
{
	return spawnArea;
}

void SpawnArea::setSpawnArea(const sf::FloatRect& spawnArea)
{
	this->spawnArea = spawnArea;
}

SpawnArea::SpawnArea(const ObjectIndicator entityIndicator, const EntityKind entityKind, const int minEntitiesNumber,
	int maxEntitiesNumber, sf::FloatRect spawnArea) : entityIndicator(entityIndicator), entityKind(entityKind),
	                                                   minEntitiesNumber(minEntitiesNumber), maxEntitiesNumber(maxEntitiesNumber),
													   spawnArea(spawnArea)
{

}

SpawnArea::~SpawnArea()
= default;
