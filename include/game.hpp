#pragma once

#include <vector>
#include <string>

#include "characters/player.hpp"
#include "characters/enemy.hpp"

class Game
{
public:
    void run();
private:
    void startMessage() const;
    void printPlayerSelect(const std::vector<Player>& players) const;
    void beginBattle(Player& player, Enemy& enemy);
    void restartGame(Player& player, Enemy& enemy);

    bool shouldExitGame() const;
    bool getYesOrNo(const std::string& question) const;

    size_t getPlayerSelected(const std::vector<Player>& players);
};