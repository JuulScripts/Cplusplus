#pragma once
#include "Attack.h"
#include "Player.h"
#include "Enemy.h" 
class ConsoleHelper {
public:
    static void startMenu();
    static void startEncounter(Player& player, bool won, Enemy* repeatableenemy = nullptr);
    static void showAttackChoices(Attack attacks[3]);
private:
    static void deathText();
    static void encounterText(Enemy enemy);
    static void winText();
};


