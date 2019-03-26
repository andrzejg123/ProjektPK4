#include "stdafx.h"
#include "RogueArcher.h"
#include "MathHelper.h"
#include "TexturesHolder.h"
#include "Log.h"
#include "FlyingObjectFactory.h"

void RogueArcher::onDeath()
{

}

void RogueArcher::onGetHit()
{

}

AttackData RogueArcher::getAttackData()
{
	auto data = AttackData();
	data.attackType = AttackType::Arrow;
	data.damage = damage;
	return data;
}

RogueArcher::RogueArcher(sf::Texture& wildDogTexture, const EnemyParams& enemyParams, AnimationData& animationData) : Object(wildDogTexture), Enemy(enemyParams, animationData)
{
	sprite.setTextureRect(sf::IntRect(0, int(facing) * animationData.frameSizeY, animationData.frameSizeX, animationData.frameSizeY));
}

RogueArcher::~RogueArcher()
{
}
