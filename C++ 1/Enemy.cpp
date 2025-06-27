#include "Enemy.h"
#include "game.h"
#include <cstdlib> 
#include <ctime>   
#include <iostream>

std::string Enemy::teamnames[5] = {
    "Funky Monkeys",
    "Ninja Narwhals",
    "Sassy Penguins",
    "Laser Llamas",
    "Waffle Warriors"
};


Enemy::Enemy() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));  // Re-seed every time
    int idx = std::rand() % 5;
    Enemy::team = Enemy::teamnames[idx];
}

void Enemy::die() {
    system("cls");
    std::cout << name << "perhaps it was for the better since he promotes uhm candy.." << std::endl;
    game::player.xp += 25;
    game::player.updateLevel();
    delete this;  // Only if allocated with 'new'
}