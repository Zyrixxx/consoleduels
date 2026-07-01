#include "characters/base/character.hpp"

#include <print>

Character::Character(const std::string& name, int health, int maxHealth)
    : name_(name), healthComponent_(health, maxHealth), weaponComponent_() {}

const std::string& Character::getName() const
{
    return name_;
}

bool Character::isDead() const
{
    return healthComponent_.isDead();
}

int Character::getHealth() const
{
    return healthComponent_.getHealth();
}

void Character::equipWeapon(const WeaponData& weapon)
{
    weaponComponent_.equip(weapon);
}

const std::string& Character::getWeaponName() const
{
    return weaponComponent_.getName();
}

void Character::Attack(Character& target)
{
    const int amount = weaponComponent_.getDamage();
    if (amount <= 0 || isDead() || target.isDead()) {
        return;
    }

    target.TakeDamage(amount);
    std::println("{} attacks {} with {} for {} damage.\n",
        name_, target.getName(), weaponComponent_.getName(), amount);
    std::println("{} now has {} health.\n", target.getName(), target.getHealth());
    if (target.isDead()) {
        std::println("{} has died.\n", target.getName());
    }
}

void Character::TakeDamage(int amount)
{
    healthComponent_.takeDamage(amount);
}

void Character::Heal(int amount)
{
    healthComponent_.heal(amount);
}

void Character::resetStats()
{
    healthComponent_.resetHealth();
}
