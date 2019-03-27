#pragma once

enum class DamageType
{
	Unknown,
	Fire,
	Ice,
	TwoHandedWeapon,
	OneHandedWeapon,
	Dagger,
	Arrow,
	Quarrel
};

struct Damage
{
	DamageType damageType = DamageType::Unknown;
	float baseDamage = 0.0f;
	float piercingAttackChance = 0.0f;
	float criticalAttackChance = 0.0f;
};

struct Defense
{
	float armor = 0.0f;
	float magicDefense = 0.0f;
	float dodgeChance = 0.0f;
	float fireResistance = 0.0f;
	float iceResistance = 0.0f;
	float twoHandedWeaponResistance = 0.0f;
	float oneHandedWeaponResistance = 0.0f;
	float daggerResistance = 0.0f;
	float arrowResistance = 0.0f;
	float quarrelResistance = 0.0f;
};

class DamageHelper
{
public:
	static float calculateDamage(const Damage& damage, const Defense& defense);
};

