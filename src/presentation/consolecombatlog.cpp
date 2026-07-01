#include "presentation/consolecombatlog.hpp"
#include <print>

void ConsoleCombatLog::bind(Character& character)
{
    character.onHealthChanged_.add([&character](const HealthChangedEvent& e) {
        std::println("{} health: {}/{}",
            character.getName(), e.currentHealth, e.maxHealth);
    });

    character.onDeath_.add([&character](const DeathEvent& e) {
        if (e.isDead) {
            std::println("{} has died.\n", character.getName());
        }
    });

    character.onAttack_.add([](const AttackEvent& e) {
        std::println("{} attacks {} with {} for {} damage.\n",
            e.attackerName, e.targetName, e.weaponName, e.damage);
    });
}