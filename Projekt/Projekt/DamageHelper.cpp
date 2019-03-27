#include "stdafx.h"
#include "DamageHelper.h"
#include "RandomHelper.h"
#include "Log.h"

float DamageHelper::calculateResistances(const float currentDamage, const Damage& damage, const Defense& defense)
{
	switch (damage.damageType) {
		case DamageType::Unknown: return currentDamage;
		case DamageType::Fire: return currentDamage - (currentDamage * defense.fireResistance / 100.0f);
		case DamageType::Ice: return currentDamage - (currentDamage * defense.iceResistance / 100.0f);
		case DamageType::TwoHandedWeapon: return currentDamage - (currentDamage * defense.twoHandedWeaponResistance / 100.0f);
		case DamageType::OneHandedWeapon: return currentDamage - (currentDamage * defense.oneHandedWeaponResistance / 100.0f);
		case DamageType::Dagger: return currentDamage - (currentDamage * defense.daggerResistance / 100.0f);
		case DamageType::Arrow: return currentDamage - (currentDamage * defense.arrowResistance / 100.0f);
		case DamageType::Quarrel: return currentDamage - (currentDamage * defense.quarrelResistance / 100.0f);
		default: return currentDamage;
	}
}

float DamageHelper::calculateDefense(const float currentDamage, const Damage& damage, const Defense& defense)
{
	if(RandomHelper::rollPercent(damage.piercingAttackChance))
	{
		if (damage.damageType == DamageType::Fire || damage.damageType == DamageType::Ice)
			return currentDamage - (defense.magicDefense / 10.0f);
		return currentDamage;
	}
	if (damage.damageType == DamageType::Fire || damage.damageType == DamageType::Ice)
		return currentDamage - (defense.magicDefense / 10.0f) - (defense.armor / 40.0f);
	return currentDamage - (defense.armor / 10.0f);
}

float DamageHelper::calculateDamage(const Damage& damage, const Defense& defense)
{
	if (RandomHelper::rollPercent(defense.dodgeChance))
		return 0.0f;
	auto currentDamage = damage.baseDamage;
	currentDamage = calculateResistances(currentDamage, damage, defense);
	currentDamage = calculateDefense(currentDamage, damage, defense);
	if (currentDamage < 1.0f)
		currentDamage = 1.0f;
	if (RandomHelper::rollPercent(damage.criticalAttackChance))
		currentDamage *= 2.0f;
	Log::debugS("dealt damage = " + std::to_string(currentDamage));
	return currentDamage;
}
