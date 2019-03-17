#pragma once
#include "Enemy.h"

class WildDog : public Enemy
{
public:
	void onDeath() override;
	void onGetHit() override;
	void attack(Player* player, GameObjectsController* gameObjectsController, GameTexturesHolder* gameTexturesHolder) override;
	WildDog(sf::Texture& wildDogTexture);
	~WildDog();
};

