#include "Player.h"
#include "ConsoleHelper.h"
void Player::updateLevel() {
    if (xp >= 100.0f) {
        level++;
        xp = 0;
    }
}


void Player::PickAttack() {
    ConsoleHelper::showAttackChoices(attacks);

}