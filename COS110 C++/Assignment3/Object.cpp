#include "Object.h"

using namespace std;
Object::Object(int x, int y)
{
    xPos = x;
    yPos = y;
    icon = '?';
}
char Object::getIcon()
{
    if(!above)
        return icon;
    else
        return above->getIcon();
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