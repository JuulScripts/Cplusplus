#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	std::string team;
	static std::string teamnames[5];
	Enemy();
	void die() override;
};
