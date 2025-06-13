#pragma once
#include "AttackTypes.h"
#include <vector>
#include <string>

class Attack
{
public: 
	AttackTypes::Type attackType;
	int baseDamage; 
	std::string name;
	static std::vector<std::string> names;
	Attack();
private: 
	void getRandomAttackType();
	std::string displayAttackText(std::string plrname);
};

