#pragma once
#include "Enemy.h"

class WildDog : public Enemy
{
protected:
	void onDeath() override;
	void onGetHit() override;
public:
	AttackType getAttackType() override;
	WildDog(sf::Texture& wildDogTexture, EnemyParams* enemyParams);
	~WildDog();
};

