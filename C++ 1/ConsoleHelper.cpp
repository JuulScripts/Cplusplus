#include "ConsoleHelper.h"
#include <iostream>


void ConsoleHelper::startMenu() {
    std::cout << "=== Pokemon but with eh people i geuss? ===" << std::endl;
    std::cout << "1. Start a fight against a crazy person" << std::endl;
    std::cout << "2. Exit" << std::endl;
}

void  ConsoleHelper::showAttackChoices(Attack attacks[3]) {
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ". " << attacks[i].name << std::endl;
    }
}

void ConsoleHelper::startEncounter() {
    std::cout << "looking for crazy person..." << std::endl;
    encounterText();
   
    bool playerWon = true;
    if (playerWon) {
        winText();
    }
    else {
        deathText();
    }
}

void ConsoleHelper::deathText() {
    std::cout << "You have been sent to heaven (i think atleast (or are you a mean person?)) either way your dead GONE NONE EXISTENT YOUR BODY IS DEAD IT DOESNT FUNCTION OR THINK though did it even think to begin with? i mean why the heck would u go around fighting random crazy people....." << std::endl;
}

void ConsoleHelper::encounterText() {
    std::cout << "Crazy person found!" << std::endl;
}

void ConsoleHelper::winText() {
    std::cout << "Congratulations! You stole the very legal substance from the crazy person you win!!!" << std::endl;
}
