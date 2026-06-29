#pragma once

#include "../include/character.hpp"
#include <string>

class Player : public Character
{
public:
    Player(const std::string& name, int health, int maxHealth);
};