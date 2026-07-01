#pragma once

#include <string>

#include "components/healthcomponent.hpp"
#include "components/weaponcomponent.hpp"
#include "components/weapondata.hpp"

class Character {
public:
    Character(const std::string& name, int health, int maxHealth);

    const std::string& getName() const;

    bool isDead() const;
    int getHealth() const;

    void equipWeapon(const WeaponData& weapon);
    const std::string& getWeaponName() const;

    void Attack(Character& target);
    void TakeDamage(int amount);
    void Heal(int amount);
    void resetStats();

protected:
    std::string name_;
    HealthComponent healthComponent_;
    WeaponComponent weaponComponent_;
};
