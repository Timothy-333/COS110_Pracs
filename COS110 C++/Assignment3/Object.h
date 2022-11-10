#ifndef OBJECT_H
#define OBJECT_H

#include <sstream>

class Object
{
protected:
    char icon;
    int xPos;
    int yPos;
    bool solid;
    bool lit;
public:
    Object* nextHoriz;
    Object* nextVert;
    Object* prevHoriz;
    Object* prevVert;
    Object* above;
    Object* below;

    Object(int, int);
    char getIcon();
    int getCoord(bool);
    Object* getNext(bool);
    Object* getPrev(bool);
    void setNext(Object*, bool);
    void setPrev(Object*, bool);
    virtual void update();
    bool isSolid();
    virtual void updateLight(char, int);
    virtual void interact();
};
#endif