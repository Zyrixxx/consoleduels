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
    void enterPrompt() const;
    void welcomeScreen() const;
    void printPlayerSelect() const;
    void displayPlayerInfo(const Player& selectedPlayer, const Enemy& enemy) const;
    void beginBattle(Player& player, Enemy& enemy);
    bool shouldExitGame() const;
    bool getYesOrNo(const std::string& question) const;
    int getPlayerSelected(const std::vector<Player>& players);
};