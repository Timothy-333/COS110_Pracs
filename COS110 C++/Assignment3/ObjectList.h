#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "Object.h"
#include <string>
using namespace std;
class ObjectList
{
private:
    bool dimension;
    Object* head;
    Object* current;
public:
    ObjectList(bool);
    void add(Object*);
    Object* getHead();
    string print();
    void reset();
    Object* iterate();
    string debug();
};
#endif