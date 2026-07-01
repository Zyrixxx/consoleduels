#include "characters/base/character.hpp"

Character::Character(const std::string& name, int health, int maxHealth)
    : name_(name), healthComponent_(health, maxHealth), weaponComponent_() {
        healthComponent_.onHealthChanged_.add([this](const HealthChangedEvent& e) {
            auto event = e;
            onHealthChanged_.broadcast(event);
        });
        healthComponent_.onDeath_.add([this](const DeathEvent& e) {
            auto event = e;
            onDeath_.broadcast(event);
        });

    }

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
    if (amount <= 0 || isDead() || target.isDead()) return;
    target.TakeDamage(amount);
    onAttack_.broadcast({name_, target.getName(), weaponComponent_.getName(), amount});
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
