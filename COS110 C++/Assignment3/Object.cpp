#include "Object.h"

using namespace std;
Object::Object(int x, int y)
{
    xPos = x;
    yPos = y;
    icon = '?';
    lit = true;
    solid = true;
    nextHoriz = NULL;
    nextVert = NULL;
    prevHoriz = NULL;
    prevVert = NULL;
    above = NULL;
    below = NULL;
}
char Object::getIcon()
{
    if(lit)
    {
        if(!above)
            return icon;
        else
            return above->getIcon();
    }
    else
        return ' ';
}
int Object::getCoord(bool dimension)
{
    if(dimension)
        return yPos;
    else
        return xPos;
}
Object* Object::getNext(bool dimension)
{
    if(dimension)
        return nextVert;
    else
        return nextHoriz;
}
Object* Object::getPrev(bool dimension)
{
    if(dimension)
        return prevVert;
    else
        return prevHoriz;
}
void Object::setNext(Object* next, bool dimension)
{
    if(dimension)
        nextVert = next;
    else
        nextHoriz = next;
}
void Object::setPrev(Object* prev, bool dimension)
{
    if(dimension)
        prevVert = prev;
    else
        prevHoriz = prev;
}
void Object::update()
{
    lit = false;
}
bool Object::isSolid()
{
    if(solid)
        return true;

    if(!above)
        return solid;
    else
        return above->isSolid();
}
void Object::interact()
{
}
void Object::updateLight(char direction, int intensity)
{
    lit = true;
    if(intensity > 1)
    {
        if(prevVert != NULL)
        {
            if(direction == 'u')
                prevVert->updateLight('u', intensity - 1);
            else
                prevVert->updateLight('n', 1); 
        }
        if(nextVert != NULL)
        {
            if(direction == 'd')
                nextVert->updateLight('d', intensity - 1);
            else
                nextVert->updateLight('n', 1);
        }
        if(prevHoriz != NULL)
        {
            if(direction == 'l')
                prevHoriz->updateLight('l', intensity - 1);
            else
                prevHoriz->updateLight('n', 1);
        }
        if(nextHoriz != NULL)
        {
            if(direction == 'r')
                nextHoriz->updateLight('r', intensity - 1);
            else
                nextHoriz->updateLight('n', 1);
        }
    }
}