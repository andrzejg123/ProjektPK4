#pragma once
#include "Enemy.h"

class WildDog : public Enemy
{
protected:
	void onDeath() override;
	void onGetHit() override;
public:
	void attack(Player* player, GameObjectHolder* gameObjectsController, GameTexturesHolder* gameTexturesHolder) override;
	WildDog(sf::Texture& wildDogTexture, EnemyParams* enemyParams);
	~WildDog();
};

