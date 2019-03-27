#pragma once
#include "DamageHelper.h"
#include <string>
#include <map>

enum class Rank
{
	Normal,
	Special,
	Epic,
	Boss
};

class EnemyParams
{
	bool ranged;
	int level;
	float speed;
	float positionX;
	float positionY;
	float visionRadius;
	float attackRadius;
	float health;
	float attackSpeed;
	Damage damage;
	Defense defense;
	Rank rank;
	void setDefaultValues();
	void scaleWithLevel();
	explicit EnemyParams();
public:
	float getAttackRadius() const;
	float getVisionRadius() const;
	float getPositionX() const;
	float getPositionY() const;
	float getSpeed() const;
	float getHealth() const;
	float getAttackSpeed() const;
	Defense getDefense() const;
	Damage getDamage() const;
	int getLevel() const;



	class Builder
	{
		std::string attackRadiusKey = "multiplyAttackRadius";
		std::string visionRadiusKey = "multiplyVisionRadius";
		std::string speedKey = "multiplySpeed";
		std::string healthKey = "multiplyHealth";
		std::string attackSpeedKey = "multiplyAttackSpeed";
		std::string armorKey = "multiplyArmor";
		std::string magicDefenseKey = "multiplyMagicDefense";
		std::string damageKey = "multiplyDamage";

		std::string dodgeChanceKey = "setDodgeChance";
		std::string globalResistanceKey = "setGlobalResistance";
		std::string fireResistanceKey = "setFireResistance";
		std::string iceResistanceKey = "setIceResistance";
		std::string twoHandedResistanceKey = "setTwoHandedWeaponResistance";
		std::string oneHandedResistanceKey = "setOneHandedWeaponResistance";
		std::string daggerResistanceKey = "setDaggerResistance";
		std::string arrowResistanceKey = "setArrowResistance";
		std::string quarrelResistanceKey = "setQuarrelResistance";
		std::string	piercingAttackChanceKey = "setPiercingAttackChance";
		std::string criticalAttackChanceKey = "setCriticalAttackChance";
		EnemyParams* enemyParams;
	public:
		Builder& setPosition(float positionX, float positionY);

		Builder& multiplyAttackRadiusByValue(float value);
		Builder& multiplyVisionRadiusByValue(float value);
		Builder& multiplySpeedByValue(float value);
		Builder& multiplyHealthByValue(float value);
		Builder& multiplyArmorByValue(float value);
		Builder& multiplyMagicDefenseByValue(float value);
		Builder& multiplyDamageByValue(float value);
		Builder& multiplyAttackSpeed(float value);
		Builder& addFileEnemyParams(const std::map<std::string, float>& enemyParamsFactors);

		Builder& setRank(Rank rank);
		Builder& setRanged(bool ranged);
		Builder& setLevel(int level);
		Builder& setDodgeChance(float dodgeChance);
		Builder& setGlobalResistance(float globalResistance);
		Builder& setFireResistance(float fireResistance);
		Builder& setIceResistance(float iceResistance);
		Builder& setTwoHandedWeaponResistance(float twoHandedWeaponResistance);
		Builder& setOneHandedWeaponResistance(float oneHandedWeaponResistance);
		Builder& setDaggerResistance(float daggerResistance);
		Builder& setArrowResistance(float arrowResistance);
		Builder& setQuarrelResistance(float quarrelResistance);
		Builder& setPiercingAttackChance(float piercingAttackChance);
		Builder& setCriticalAttackChance(float criticalAttackChance);
		Builder& setDamageType(const DamageType& damageType);
		EnemyParams build() const;
		explicit Builder();

	};

};

