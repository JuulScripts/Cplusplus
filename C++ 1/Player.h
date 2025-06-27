#include "Character.h"
#include "AttackTypes.h" 
#include "Enemy.h"
#pragma once
class Player : public Character {
public:
    int level;
    float xp;
    bool hasDied;
    int battlesFought;
    int battlesWon;
    void die() override;
    Player(int health);
    bool PickAttack(Enemy& enemy);
    void updateLevel();
private:
    int choise;
};


