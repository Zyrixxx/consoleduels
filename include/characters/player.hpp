#pragma once

#include "base/character.hpp"
#include <string>

class Player : public Character
{
public:
    Player(const std::string& name, int health, int maxHealth);
};