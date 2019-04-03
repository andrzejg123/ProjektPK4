#pragma once
#include "Damageable.h"
#include "Item.h"

enum class WeaponType
{
	OneHandedSword,
	TwoHandedSword,
	Bow,
	Magic
};

class Weapon : public Item
{
	DamageType damageType;
	WeaponType type;
public:
	Weapon();
	~Weapon();
};

