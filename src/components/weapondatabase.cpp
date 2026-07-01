#include "components/weapondatabase.hpp"

#include <fstream>
#include <print>

#include <nlohmann/json.hpp>

bool WeaponDatabase::loadFromFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file) {
        std::println("[WeaponDatabase] Could not open '{}'. Falling back to default weapon.", path);
        return false;
    }

    try {
        const nlohmann::json data = nlohmann::json::parse(file);
        for (const auto& entry : data.at("weapons")) {
            WeaponData weapon;
            weapon.id = entry.at("id").get<std::string>();
            weapon.name = entry.at("name").get<std::string>();
            weapon.damage = entry.at("damage").get<int>();
            weapons_[weapon.id] = weapon;
        }
    }
    catch (const std::exception& e) {
        std::println("[WeaponDatabase] Failed to parse '{}': {}", path, e.what());
        return false;
    }

    return true;
}

const WeaponData& WeaponDatabase::get(const std::string& id) const
{
    const auto it = weapons_.find(id);
    if (it != weapons_.end()) {
        return it->second;
    }
    return defaultWeapon_;
}

bool WeaponDatabase::contains(const std::string& id) const
{
    return weapons_.contains(id);
}
