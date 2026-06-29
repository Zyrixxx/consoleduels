#pragma once

#include <string>

class Character
{
public:
    Character(const std::string& name, int health, int maxHealth);

    bool isDead() const;

    const std::string& getName() const;

    int getHealth() const;

    void Attack(Character& target, int amount);
    void TakeDamage(int amount);
    void Heal(int amount);
    void resetStats();

protected:
    void HandleDeath();

    std::string name_;
    int health_;
    int maxHealth_;
};