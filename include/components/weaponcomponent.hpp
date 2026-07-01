#pragma once

#include <string>

#include "components/weapondata.hpp"

class WeaponComponent {
public:
    WeaponComponent() = default;
    explicit WeaponComponent(const WeaponData& weapon);

    void equip(const WeaponData& weapon);

    int getDamage() const;
    const std::string& getName() const;

private:
    WeaponData weapon_{};
};
