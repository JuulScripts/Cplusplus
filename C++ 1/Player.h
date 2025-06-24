#include "Character.h"
#include "AttackTypes.h" 
#pragma once
class Player : public Character {
public:
    int level;
    float xp;
    bool hasDied;
    int battlesFought;
    int battlesWon;

    Player(std::string name, int health, std::vector<Attack> attacks, AttackTypes::Type weakness);
    void PickAttack();
    void updateLevel();
};


