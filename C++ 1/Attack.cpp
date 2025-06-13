#include "Attack.h"
#include "AttackTypes.h"
#include <cstdlib>
#include <ctime>

std::vector<std::string> Attack::names = {
    "Strike",
    "Hit",
    "Shot",
    "Blast",
    "Slash",
    "Stab",
    "Smash",
    "Punch",
    "Kick",
    "Swing",
    "Thrust",
    "Charge",
    "Shotgun",
    "Gunshot",
    "Bolt",
    "Wave",
    "Burst",
    "Shot",
    "Pierce",
    "Slam"
};

Attack::Attack() {
	srand(time(nullptr));
	getRandomAttackType();
	baseDamage = rand() % 20;
    name = names[std::rand() % Attack::names.size()];
}




void Attack::getRandomAttackType() {
	int rindex = (rand() % 4) + 1;
	AttackTypes::Type newAttack = static_cast<AttackTypes::Type>(rindex);
	attackType = newAttack;
}

std::string Attack::displayAttackText(std::string plrname) {
    return plrname + " used " + name;
}