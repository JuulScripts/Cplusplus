    #include "Character.h"
    #include "Attack.h"
    #include <iostream>




    void Character::attack(Character Enemy, Attack move) {
	    Enemy.health -= move.baseDamage;
    }




    void Character::die() {
        std::cout << name << " died" << std::endl;
        delete this;  // Only if allocated with 'new'
    }