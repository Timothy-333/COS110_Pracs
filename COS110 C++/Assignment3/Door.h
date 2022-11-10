#ifndef DOOR_H
#define DOOR_H

#include "Object.h"
#include <string>

class Door: public Object
{
private:
    bool open;
public:
    Door(int, int, bool);
    void interact();
    void updateLight(char, int);
    bool unlock();
};

#endif
