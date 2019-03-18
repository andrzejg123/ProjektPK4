#pragma once
class EnemyParams
{
	float speed = 10;
	float positionX = 0;
	float positionY = 0;
	float visionRadius = 50;
	float attackRadius = 40;
public:
	float getAttackRadius() const;
	float getVisionRadius() const;
	float getPositionX() const;
	float getPositionY() const;
	float getSpeed() const;
	class Builder
	{
		EnemyParams* enemyParams;
	public:
		EnemyParams::Builder& setSpeed(float speed);
		EnemyParams::Builder& setPosition(float positionX, float positionY);
		EnemyParams::Builder& setVisionRadius(float visionRadius);
		EnemyParams::Builder& setAttackRadius(float attackRadius);
		EnemyParams* build() const;
		explicit Builder();
	};

};

