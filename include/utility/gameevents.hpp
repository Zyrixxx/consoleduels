#pragma once
#include <string>

struct HealthChangedEvent {
    int currentHealth;
    int maxHealth;
};

struct DeathEvent {
    bool isDead;
};

struct AttackEvent {
    std::string attackerName;
    std::string targetName;
    std::string weaponName;
    int damage;
};