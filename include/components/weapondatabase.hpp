#pragma once

#include <string>
#include <unordered_map>

#include "weapondata.hpp"

class WeaponDatabase {
public:
    bool loadFromFile(const std::string& path);

    const WeaponData& get(const std::string& id) const;
    bool contains(const std::string& id) const;

private:
    std::unordered_map<std::string, WeaponData> weapons_;
    WeaponData defaultWeapon_{};
};
