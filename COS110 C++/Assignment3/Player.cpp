#include "Player.h"

using namespace std;

Player::Player(int x, int y): Object(x, y)
{
    icon = '&';
}
void Player::move(int x, int y)
{
    xPos += x;
    yPos += y;
}