#include "ConsoleHelper.h"
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include <cstdlib> 
#include "game.h"

void ConsoleHelper::startMenu() {

    std::cout << "=== Pokemon but with... people, I guess? ===\n";
    std::cout << "1. Start a fight against a crazy person\n";
    std::cout << "2. Exit\n";
    std::cout << "3. See stats\n";
    int choise;
    std::cin >> choise;
    std::cout << "You entered: " << choise << std::endl;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number.\n";
        startMenu();  
        return;
    }
    else {
        if (choise == 1) {
            ConsoleHelper::startEncounter(game::player, false);

        }
        else if (choise == 2) {
            exit(0);
        }
        else if (choise == 3) {

            std::cout << "Name: " << game::player.name << " \nAttacks:\n"
                << game::player.attacks[0].name << "\n"
                << game::player.attacks[1].name << "\n"
                << game::player.attacks[2].name << "\n"
                << "health & levels: " << "\n Health:" << game::player.health << "\n XP:"
                << game::player.xp << "\n"
                << "type anything to go back" << std::endl;

            std::cout << "Press any key then Enter to continue...\n";

            // Clear input buffer to wait properly
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();

            system("cls");

            startMenu();
        }
        else if (choise <= 0 || choise > 3) {
            system("cls");
            startMenu();  
            return;
        }
    }
}

void ConsoleHelper::showAttackChoices(Attack attacks[3]) {
    std::cout << "\nChoose your attack:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "  " << i + 1 << ". " << attacks[i].name << "\n";
    }
}
void ConsoleHelper::startEncounter(Player& player, bool won, Enemy* repeatableenemy) {

    Enemy* enemy;
    if (repeatableenemy != nullptr) {
        enemy = repeatableenemy;
        std::cout << "\n\nStill fighting the same guy... you should have paid attention the first time, but I guess you can know his name :P\n";
        std::cout << "Enemy name: " << enemy->name << "\n\n";
    }
    else {
        enemy = new Enemy();
        encounterText(*enemy);
        std::cout << "\n";  // extra spacing for readability
    }

    bool won2 = player.PickAttack(*enemy);
    if (won2) {
        ConsoleHelper::startMenu();
        winText();
        system("clear");
    }
    else {
        enemy->attack(player, enemy->attacks[std::rand() % 3]);
        std::cout << "\nPress Enter to continue to the next round\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();

        system("cls");
        startEncounter(player, won2, enemy);
    }
  

   

    system("cls");  

  
}
void ConsoleHelper::deathText() {

    std::cout << "\n=== You Died ===\n";
    std::cout << "You've been sent to heaven... probably. Or maybe not?\n";
    std::cout << "Either way, you're DEAD. GONE. NON-EXISTENT.\n";
    std::cout << "Your body no longer functions, or thinks... though did it even think to begin with?\n";
    std::cout << "Seriously, why go around fighting random crazy people?\n";
}

void ConsoleHelper::encounterText(Enemy enemy) {
    std::cout << "\nA wild crazy person appears!\n";
    std::cout << "Enemy Team: " << enemy.team << "\n";
    std::cout << "Enemy Name: " << enemy.name << "\n";
    std::cout << "Attacks: " << enemy.attacks[0].name << ", "
        << enemy.attacks[1].name << ", "
        << enemy.attacks[2].name << "\n";
}

void ConsoleHelper::winText() {
    std::cout << "\n=== Victory ===\n";
    std::cout << "Congratulations! You stole the (totally legal) substance from the crazy person.\n";
    std::cout << "You win!!!\n";
}
