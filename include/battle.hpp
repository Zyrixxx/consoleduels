#pragma once

#include "../include/player.hpp"
#include "../include/enemy.hpp"

enum class Action {
    Attack,
    Heal,
    Block
};

enum class battleResult {
    PlayerWin,
    EnemyWin,
    Draw
};

class Battle
{
public:
    battleResult beginBattle(Player& player, Enemy& enemy);
private:

};