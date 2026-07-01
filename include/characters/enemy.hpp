#pragma once

#include "base/character.hpp"
#include <string>

class Enemy : public Character
{
public:
    Enemy(const std::string& name, int health, int maxHealth);
};