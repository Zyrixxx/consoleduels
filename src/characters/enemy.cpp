#include "../../include/characters/enemy.hpp"

Enemy::Enemy(const std::string& name, int health, int maxHealth)
    : Character(name, health, maxHealth) {}
