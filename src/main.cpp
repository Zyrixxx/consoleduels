#include <iostream>
#include <vector>
#include <string>
#include <print>
#include <limits>
#include <array>
#include <algorithm>

#include "../include/player.hpp"
#include "../include/enemy.hpp"

// Forward declarations
void enterPrompt();
void welcomeScreen();
void printPlayerSelect();
void displayPlayerInfo(const Player& selectedPlayer, const Enemy& enemy);
void beginBattle(Player& player, Enemy& enemy);

bool playAgain();
bool getYesOrNo(const std::string& question);

int getPlayerSelected(const std::vector<Player>& players);

// Main loop
int main()
{
    bool windowShouldClose{ false };

    std::vector<Player> players = {
    Player("Eric", 100, 100),
    Player("Jake", 100, 100),
    Player("Ben", 100, 100),
    Player("Terry", 100, 100)
    };

    Enemy enemy = Enemy("AI", 100, 100);

    while (!windowShouldClose)
    {
        enterPrompt();
        welcomeScreen();

        int selectedIndex = getPlayerSelected(players);
        Player& selectedPlayer = players[selectedIndex];
        displayPlayerInfo(selectedPlayer, enemy);

        beginBattle(selectedPlayer, enemy);
        windowShouldClose = playAgain();

        selectedPlayer.resetStats();
        enemy.resetStats();
    }
    return 0;
}

void enterPrompt() {
    std::println("Press Enter to continue...");
    char key = std::cin.get();
    while (key != '\n') {
        key = std::cin.get();
    }
    system("cls");
}

void welcomeScreen() {
    std::println("Welcome to Console Duels!\n");
}

void printPlayerSelect() {
    std::array<std::string, 4> names = {
        "Eric",
        "Jake",
        "Ben",
        "Terry"
    };

    std::println("Choose your character:\n");

    for (size_t i = 0; i < names.size(); ++i)
    {
        std::println("{}: {}", i + 1, names[i]);
    }
}

int getPlayerSelected(const std::vector<Player>& players) {
    while (true)
    {
        printPlayerSelect();
        int32_t playerSelection;
        std::cin >> playerSelection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            std::println("Invalid selection.\n");
            continue;
        }

        if (playerSelection < 1 || playerSelection > players.size())
        {
            system("cls");
            std::println("Invalid selection.\n");
            continue;
        }
        return playerSelection - 1; 
    }
}

void displayPlayerInfo(const Player& selectedPlayer, const Enemy& enemy) {
    system("cls");
    std::println("You have chosen: {}\n", selectedPlayer.getName());
    std::println("You're opponent is: {}\n", enemy.getName());
}

void beginBattle(Player& selectedPlayer, Enemy& enemy) {
    std::println("{} vs {}\n", selectedPlayer.getName(), enemy.getName());
    std::println("Let the battle begin!\n");
    while (!selectedPlayer.isDead() && !enemy.isDead()) {
        selectedPlayer.Attack(enemy, 10);
        enemy.Attack(selectedPlayer, 10);
        continue;
    }
    // TODO: Can currently print two winners at the same time, will fix in future update
    if (selectedPlayer.isDead()) {
        std::println("{} is the winner!\n", enemy.getName());
    }
    else if (enemy.isDead()) {
        std::println("{} is the winner!\n", selectedPlayer.getName());
    }
    else {
        std::println("The battle is a draw!\n");
    }
}

bool playAgain() {
    if (!getYesOrNo("Do you want to play again?")) {
        return true;
    }
    return false;
}

bool getYesOrNo(const std::string& question) {
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