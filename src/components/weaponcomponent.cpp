#include "components/weaponcomponent.hpp"

WeaponComponent::WeaponComponent(const WeaponData& weapon)
    : weapon_(weapon) {}

void WeaponComponent::equip(const WeaponData& weapon)
{
    weapon_ = weapon;
}

int WeaponComponent::getDamage() const
{
    return weapon_.damage;
}

const std::string& WeaponComponent::getName() const
{
    return weapon_.name;
}
