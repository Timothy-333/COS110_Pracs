#include "Lamp.h"

using namespace std;

Lamp::Lamp(int x, int y): Object(x, y)
{
    solid = false;
    icon = '^';
    lit = true;
}
void Lamp::update()
{
    this->below->updateLight('n', 1);
    if(this->below->prevVert != NULL)
        this->below->prevVert->updateLight('u', 20);
    if(this->below->nextVert != NULL)
        this->below->nextVert->updateLight('d', 20);
    if(this->below->prevHoriz != NULL)
        this->below->prevHoriz->updateLight('l', 20);
    if(this->below->nextHoriz != NULL)      
        this->below->nextHoriz->updateLight('r', 20);
}
