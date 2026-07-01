#include "../../include/characters/player.hpp"

Player::Player(const std::string& name, int health, int maxHealth)
    : Character(name, health, maxHealth) {}
