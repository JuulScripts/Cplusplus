

#include <iostream>
#include "game.h"
int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	game::start();
}
