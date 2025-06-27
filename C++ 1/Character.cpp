#include "Character.h"
#include "Attack.h"
#include <iostream>


#include <cstdlib>
#include <ctime>


std::string Character::names[20] = {
    "Greg the Unstable",
    "Susan the Screamer",
    "Toaster Steve",
    "Banana Jim",
    "Mysterious Gerald",
    "Linda Lightningfist",
    "Carl the Crawling Chaos",
    "Becky Bladewind",
    "Dumpster Dave",
    "Flamingo Frank",
    "One-Eyed Olivia",
    "Shady Sheila",
    "Bob the Disoriented",
    "Captain Crunchwrap",
    "Janet the Juggernaut",
    "Vape Wizard Vince",
    "Cursed Carlita",
    "Feral Fabio",
    "Moonhowl Marcy",
    "Chairbreaker Chad"
};


// somewhere global, e.g. main.cpp at program start:


// Character constructor:
Character::Character() {
    int nameIndex = std::rand() % 20;
    name = names[nameIndex];

    weakness = static_cast<AttackTypes::Type>(std::rand() % 4);

    for (int i = 0; i < 3; ++i) {
        attacks[i] = Attack();
        attacks[i].baseDamage += i * 5; // make attacks differ
    }

    Character::health = 100;
}



bool Character::attack(Character& Enemy, Attack move) {
    int multipliyer = 1;
    if (Enemy.weakness == move.attackType) {
        multipliyer = 2;
        std::cout << "\n OH YOUR ATTACK IS STRONG ITS THIS GUYS WEAKNESS DOUBLE DAMAGE KABLAMO \n" << std::endl;
    }
	Enemy.health -= move.baseDamage*multipliyer;
    std::cout << Enemy.name << " Took " << move.baseDamage * multipliyer << " Damage From " << move.name << std::endl;
    if (Enemy.health <= 0) {
        Enemy.die();
        return true;
    }
    return false;
}



void Character::die() {

    std::cout << name << " died... perhaps it was for the better since he promotes uhm candy.." << std::endl;
    delete this;  // Only if allocated with 'new'
}