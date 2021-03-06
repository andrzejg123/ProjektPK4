#pragma once
#include "Enemy.h"

class RogueArcher : public Enemy
{
protected:
	void onDeath() override;
	void onGetHit() override;
public:
	AttackData getAttackData() override;
	RogueArcher(sf::Texture& wildDogTexture, EnemyParams enemyParams, AnimationData& animationData);
	~RogueArcher();
};

