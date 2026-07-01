#pragma once

#include <string>

#include "components/weapondata.hpp"
#include "../utility/event.hpp"
#include "../utility/gameevents.hpp"

class WeaponComponent {
public:
    Event<AttackEvent> onAttack_;

    WeaponComponent() = default;
    explicit WeaponComponent(const WeaponData& weapon);

    void equip(const WeaponData& weapon);

    int getDamage() const;
    const std::string& getName() const;

private:
    WeaponData weapon_{};
};
