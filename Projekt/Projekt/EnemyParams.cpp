#include "stdafx.h"
#include "EnemyParams.h"
#include "Log.h"

EnemyParams::EnemyParams()
{
	rank = Rank::Normal;
	ranged = false;
	level = 1;
	attackRadius = 25.0f;
	positionX = 0.0f;
	positionY = 0.0f;
	speed = 60.0f;
	visionRadius = 110.0f;
	health = 100.0f;
	defense.armor = 100.0f;
	defense.magicDefense = 100.0f;
	damage.baseDamage = 20.0f;
	attackSpeed = 2.0f;
}

float EnemyParams::getAttackRadius() const
{
	return attackRadius;
}

float EnemyParams::getVisionRadius() const
{
	return visionRadius;
}

float EnemyParams::getPositionX() const
{
	return positionX;
}

float EnemyParams::getPositionY() const
{
	return positionY;
}

float EnemyParams::getSpeed() const
{
	return speed;
}

float EnemyParams::getHealth() const
{
	return health;
}

float EnemyParams::getAttackSpeed() const
{
	return attackSpeed;
}

Defense EnemyParams::getDefense() const
{
	return defense;
}

Damage EnemyParams::getDamage() const
{
	return damage;
}

int EnemyParams::getLevel() const
{
	return level;
}

EnemyParams::Builder& EnemyParams::Builder::multiplySpeedByValue(const float value)
{
	enemyParams->speed *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyHealthByValue(const float value)
{
	enemyParams->health *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyArmorByValue(const float value)
{
	enemyParams->defense.armor *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyMagicDefenseByValue(const float value)
{
	enemyParams->defense.magicDefense *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setPosition(const float positionX, const float positionY)
{
	enemyParams->positionX = positionX;
	enemyParams->positionY = positionY;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyVisionRadiusByValue(const float value)
{
	enemyParams->visionRadius *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyAttackRadiusByValue(const float value)
{
	enemyParams->attackRadius = value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setDodgeChance(const float dodgeChance)
{
	enemyParams->defense.dodgeChance = dodgeChance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setGlobalResistance(const float globalResistance)
{
	enemyParams->defense.fireResistance = globalResistance;
	enemyParams->defense.iceResistance = globalResistance;
	enemyParams->defense.twoHandedWeaponResistance = globalResistance;
	enemyParams->defense.oneHandedWeaponResistance = globalResistance;
	enemyParams->defense.daggerResistance = globalResistance;
	enemyParams->defense.arrowResistance = globalResistance;
	enemyParams->defense.quarrelResistance = globalResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setFireResistance(const float fireResistance)
{
	enemyParams->defense.fireResistance = fireResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setIceResistance(const float iceResistance)
{
	enemyParams->defense.iceResistance = iceResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setTwoHandedWeaponResistance(const float twoHandedWeaponResistance)
{
	enemyParams->defense.twoHandedWeaponResistance = twoHandedWeaponResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setOneHandedWeaponResistance(const float oneHandedWeaponResistance)
{
	enemyParams->defense.oneHandedWeaponResistance = oneHandedWeaponResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setDaggerResistance(const float daggerResistance)
{
	enemyParams->defense.daggerResistance = daggerResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setArrowResistance(const float arrowResistance)
{
	enemyParams->defense.arrowResistance = arrowResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setQuarrelResistance(const float quarrelResistance)
{
	enemyParams->defense.quarrelResistance = quarrelResistance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setDamageType(const DamageType& damageType)
{
	enemyParams->damage.damageType = damageType;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setPiercingAttackChance(const float piercingAttackChance)
{
	enemyParams->damage.piercingAttackChance = piercingAttackChance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setCriticalAttackChance(const float criticalAttackChance)
{
	enemyParams->damage.criticalAttackChance = criticalAttackChance;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyDamageByValue(const float value)
{
	enemyParams->damage.baseDamage *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::multiplyAttackSpeed(const float value)
{
	enemyParams->attackSpeed *= value;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::addFileEnemyParams(const std::map<std::string, float>& enemyParamsFactors)
{
	for (const auto enemyParamsFactor : enemyParamsFactors)
	{
		if (enemyParamsFactor.first._Equal(damageKey))
			enemyParams->damage.baseDamage *= enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(armorKey))
			enemyParams->defense.armor *= enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(piercingAttackChanceKey))
			enemyParams->damage.piercingAttackChance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(criticalAttackChanceKey))
			enemyParams->damage.criticalAttackChance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(fireResistanceKey))
			enemyParams->defense.fireResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(iceResistanceKey))
			enemyParams->defense.iceResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(twoHandedResistanceKey))
			enemyParams->defense.twoHandedWeaponResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(oneHandedResistanceKey))
			enemyParams->defense.oneHandedWeaponResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(daggerResistanceKey))
			enemyParams->defense.daggerResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(arrowResistanceKey))
			enemyParams->defense.arrowResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(quarrelResistanceKey))
			enemyParams->defense.quarrelResistance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(globalResistanceKey))
		{
			enemyParams->defense.fireResistance = enemyParamsFactor.second;
			enemyParams->defense.iceResistance = enemyParamsFactor.second;
			enemyParams->defense.twoHandedWeaponResistance = enemyParamsFactor.second;
			enemyParams->defense.oneHandedWeaponResistance = enemyParamsFactor.second;
			enemyParams->defense.daggerResistance = enemyParamsFactor.second;
			enemyParams->defense.arrowResistance = enemyParamsFactor.second;
			enemyParams->defense.quarrelResistance = enemyParamsFactor.second;
		} 
		else if (enemyParamsFactor.first._Equal(dodgeChanceKey))
			enemyParams->defense.dodgeChance = enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(attackRadiusKey))
			enemyParams->attackRadius *= enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(visionRadiusKey))
			enemyParams->visionRadius *= enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(speedKey))
			enemyParams->speed *= enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(healthKey))
			enemyParams->health *= enemyParamsFactor.second;
		else if (enemyParamsFactor.first._Equal(attackSpeedKey))
			enemyParams->attackSpeed *= enemyParamsFactor.second;
	}
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setRank(const Rank rank)
{
	enemyParams->rank = rank;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setRanged(const bool ranged)
{
	enemyParams->ranged = true;
	return *this;
}

EnemyParams::Builder& EnemyParams::Builder::setLevel(const int level)
{
	enemyParams->level = level;
	return *this;
}

EnemyParams EnemyParams::Builder::build() const
{
	const auto floatLvl = float(enemyParams->level);
	switch (enemyParams->rank) { 
		case Rank::Normal: break;
		case Rank::Special: break;
		case Rank::Epic: break;
	default: ;
	}
	if(enemyParams->ranged)
		enemyParams->attackRadius += 80.0f;
	enemyParams->speed += floatLvl;
	enemyParams->visionRadius += floatLvl;
	enemyParams->health += (floatLvl * 2.0f);
	enemyParams->defense.armor += (floatLvl * 2.0f);
	enemyParams->defense.magicDefense += (floatLvl * 2.0f);
	enemyParams->damage.baseDamage += floatLvl;
	enemyParams->attackSpeed = 2.0f;
	if(enemyParams->visionRadius < enemyParams->attackRadius)
		Log::debug("Warning: vision radius is lower attack radius");
	const auto enemyParams = *this->enemyParams;
	delete this->enemyParams;
	return enemyParams;
}

EnemyParams::Builder::Builder()
{
	this->enemyParams = new EnemyParams();
}
