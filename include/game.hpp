#pragma once

#include <vector>
#include <string>

#include "../include/player.hpp"
#include "../include/enemy.hpp"

class Game
{
public:
    void run();
private:
    void enterMessage() const;
    void welcomeMessage() const;
    void printPlayerSelect(const std::vector<Player>& players) const;
    void displayPlayerInfo(const Player& player, const Enemy& enemy) const;
    void beginBattle(Player& player, Enemy& enemy);
    bool shouldExitGame() const;
    bool getYesOrNo(const std::string& question) const;
    size_t getPlayerSelected(const std::vector<Player>& players);
};