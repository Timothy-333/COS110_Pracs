#ifndef MAP_H
#define MAP_H
#include "ObjectList.h"
#include <string>
class Map
{
private:
    int width;
    int height;
    ObjectList** rows;
    ObjectList** columns;
    ObjectList* lights;
public:
    Map(int, int);
    ~Map();
    void add(Object*);
    string print();
    void addLight(Object*);
    Object* getAt(int, int);
    void resetEnvironment();
    void updateEnvironment();
};
#endif

