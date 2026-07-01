#pragma once

#include <string>

#include "components/healthcomponent.hpp"
#include "components/weaponcomponent.hpp"
#include "components/weapondata.hpp"
#include "../../utility/event.hpp"
#include "../../utility/gameevents.hpp"

class Character {
public:
    Character(const std::string& name, int health, int maxHealth);
    Event<HealthChangedEvent> onHealthChanged_;
    Event<DeathEvent> onDeath_;
    Event<AttackEvent> onAttack_;

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
