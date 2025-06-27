#include "Player.h"
#include "ConsoleHelper.h"
#include <iostream>
#include "game.h"
void Player::updateLevel() {
    if (xp >= 100.0f) {
        level++;
        xp = 0;
        std::cout << "Level up, reset health to 100!!";
        Player::health = 300;
    }
}
Player::Player(int health) {
    this->health = health;
}

void Player::die() {
    system("cls");
    std::cout << "your trash you died ur terrible this is why nobody loves you. \n \n";
    level = 0;
    xp = 0;
    health = 300;
    ConsoleHelper::startMenu();
}
bool Player::PickAttack(Enemy& enemy) {
    const int attackCount = 3; 

    ConsoleHelper::showAttackChoices(attacks);

    int choice;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice < 0 || choice > attackCount) {
            std::cout << "Invalid choice. Please enter a number between 1 and " << attackCount  << ".\n";
            continue;
        }

        std::cout << "You entered: " << choice << "\n";
        break;
    }

    bool won = Player::attack(enemy, attacks[choice-1]);
    return won;
}
