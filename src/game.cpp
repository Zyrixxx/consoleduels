#include "game.hpp"
#include "utility/console_utils.hpp"
#include "components/weapondatabase.hpp"

#include <iostream>
#include <print>
#include <algorithm>


void Game::run()
{
    WeaponDatabase weapons;
    weapons.loadFromFile("data/weapons.json");

    std::vector players = {
        Player("Eric", 100, 100),
        Player("Jake", 100, 100),
        Player("Ben", 100, 100),
        Player("Terry", 100, 100)
        };

    players[0].equipWeapon(weapons.get("sword"));
    players[1].equipWeapon(weapons.get("axe"));
    players[2].equipWeapon(weapons.get("dagger"));
    players[3].equipWeapon(weapons.get("hammer"));

    auto enemy = Enemy("AI", 100, 100);
    enemy.equipWeapon(weapons.get("sword"));

    bool windowShouldClose{ false };

    while (!windowShouldClose)
    {
        enterMessage();
        welcomeMessage();

        const auto selectedIndex = getPlayerSelected(players);
        auto& player = players[selectedIndex];
        displayPlayerInfo(player, enemy);

        beginBattle(player, enemy);
        windowShouldClose = shouldExitGame();

        player.resetStats();
        enemy.resetStats();
    }
}

void Game::enterMessage() const {
    std::println("Press Enter to continue...");
    char key = std::cin.get();
    while (key != '\n') {
        key = std::cin.get();
    }
    clearScreen();
}

void Game::welcomeMessage() const {
    std::println("Welcome to Console Duels!\n");
}


void Game::printPlayerSelect(const std::vector<Player>& players) const {
    std::println("Choose your character:\n");

    for (size_t i = 0; i < players.size(); ++i)
    {
        std::println("{}: {}", i + 1, players[i].getName());
    }
}

size_t Game::getPlayerSelected(const std::vector<Player>& players){
    while (true)
    {
        printPlayerSelect(players);
        size_t playerSelection;
        std::cin >> playerSelection;
        flushInputLine();

        if (std::cin.fail() || playerSelection < 1 || playerSelection > players.size())
        {
            handleInputError();
            std::println("Invalid selection.\n");
            continue;
        }
        return playerSelection - 1; 
    }
}

void Game::displayPlayerInfo(const Player& player, const Enemy& enemy) const {
    clearScreen();
    std::println("You have chosen: {}\n", player.getName());
    std::println("You're opponent is: {}\n", enemy.getName());
}

// TODO: Get rid of this code once battle class is implemented
void Game::beginBattle(Player& player, Enemy& enemy) {
    std::println("{} vs {}\n", player.getName(), enemy.getName());
    std::println("Let the battle begin!\n");
    while (!player.isDead() && !enemy.isDead()) {
        player.Attack(enemy);
        enemy.Attack(player);
    }

    if (player.isDead()) {
        std::println("{} is the winner!\n", enemy.getName());
    }
    else if (enemy.isDead()) {
        std::println("{} is the winner!\n", player.getName());
    }
    else {
        std::println("The battle is a draw!\n");
    }
}

bool Game::shouldExitGame() const {
    if (getYesOrNo("Do you want to exit the game?")) {
        return true;
    }
    return false;
}

bool Game::getYesOrNo(const std::string& question) const {
    std::string input;
    while (true) {
        std::cout << question << " (Y/N): ";
        std::cin >> input;
        std::ranges::transform(input, input.begin(),
            [](unsigned char c) {
                return static_cast<char>(std::tolower(c));
            });
        if (input == "y") return true;
        if (input == "n") return false;
        std::cout << "Invalid input. Please enter Y or N.\n";
    }
}