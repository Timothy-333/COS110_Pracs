#include "Door.h"

using namespace std;

Door::Door(int x, int y, bool open): Object(x, y)
{
    this->open = open;
    if(open)
    {
        icon = '=';
        solid = false;
    }
    else
    {
        icon = '+';
        solid = true;
    }
}
void Door::interact()
{
    if(open)
    {
        icon = '+';
        solid = true;
        string message = "You closed a door";
        open = !open;
        throw message;
    }
    else
    {
        icon = '=';
        solid = false;
        string message = "You opened a door";
        open = !open;
        throw message;
    }
}
void Door::updateLight(char direction, int intensity)
{
    if(!solid)
        Object::updateLight(direction, intensity);
    else
        lit = true;
}
