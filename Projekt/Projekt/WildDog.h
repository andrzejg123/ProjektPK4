#pragma once
#include "Enemy.h"

class GameTexturesHolder;

class WildDog : public Enemy
{
public:
	void attack(Player* player, void* gameObjectsHolder, GameTexturesHolder* gameTexturesHolder) override;
	WildDog(sf::Texture& wildDogTexture);
	~WildDog();
};

