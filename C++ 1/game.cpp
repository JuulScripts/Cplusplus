#include "game.h"
#include "ConsoleHelper.h"

Player game::player = Player(300);

void game::start() {
	ConsoleHelper::startMenu();
}