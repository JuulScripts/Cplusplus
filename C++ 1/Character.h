#pragma once
#include <string>;
#include "Attack.h";
#include "AttackTypes.h"
class Character
{
public: 
	int health;
	std::string name;
	AttackTypes::Type weakness;
	void attack(Character Enemy, Attack move);
	void die(); 

    //add weakness later and attack to
private:
	Attack attacks[3] = {};
};

