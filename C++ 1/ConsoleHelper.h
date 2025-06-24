#pragma once
#include "Attack.h";
class ConsoleHelper {
public:
    static void startMenu();
    static void startEncounter();
    static void showAttackChoices(Attack attacks[3]);
private:
    static void deathText();
    static void encounterText();
    static void winText();
};


