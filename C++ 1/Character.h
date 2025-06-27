#pragma once
#include <string>
#include "Attack.h"
#include "AttackTypes.h"
class Character
{
public: 
	int health;
	std::string name;
	AttackTypes::Type weakness;
	bool attack(Character& Enemy, Attack move);
    virtual void die(); 
	Attack attacks[3];
	Character();
private: 
	static std::string names[20];
};

