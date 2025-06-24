#include "Character.h"
#include "Attack.h"
#include <iostream>




void Character::attack(Character& Enemy, Attack move) {
    int multipliyer = 1;
    if (Enemy.weakness == move.attackType)
        multipliyer = 2; 

	Enemy.health -= move.baseDamage;
    if (Enemy.health >= 0) {
        Enemy.die();
    }

}




void Character::die() {
    std::cout << name << " died... perhaps it was for the better" << std::endl;
    delete this;  // Only if allocated with 'new'
}