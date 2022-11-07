#include "Player.h"

using namespace std;

Player::Player(int x, int y): Object(x, y)
{
    icon = '&';
}
void Player::move(int x, int y)
{
    Object* floorPtr = NULL;
    floorPtr = this;
    while(floorPtr->below != NULL)
        floorPtr = floorPtr->below;
    floorPtr->above = NULL;
    if (x)
    {
        /* code */
    }
    
}