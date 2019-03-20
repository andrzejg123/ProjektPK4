#pragma once

struct EnemyParamsFactors
{
	float visionRadiusFactor;
	float armorFactor;
	float healthFactor;
	float attackRadiusFactor;
	float speedFactor;
};

class EnemyParams
{
	float speed;
	float positionX;
	float positionY;
	float visionRadius;
	float attackRadius;
	float health;
	float armor;
	float damage;
	explicit EnemyParams(int lvl);
public:
	float getAttackRadius() const;
	float getVisionRadius() const;
	float getPositionX() const;
	float getPositionY() const;
	float getSpeed() const;
	float getHealth() const;
	float getArmor() const;
	float getDamage() const;
	class Builder
	{
		EnemyParams* enemyParams;
	public:
		EnemyParams::Builder& multiplyVisionRadiusByValue(float value);
		EnemyParams::Builder& multiplySpeedByValue(float value);
		EnemyParams::Builder& multiplyHealthByValue(float value);
		EnemyParams::Builder& multiplyArmorByValue(float value);
		EnemyParams::Builder& setPosition(float positionX, float positionY);
		EnemyParams::Builder& setAttackRadius(float attackRadius);
		EnemyParams::Builder& multiplyDamageByValue(float value);
		EnemyParams* build() const;
		explicit Builder(int lvl);
	};

};

