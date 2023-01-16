#include "Map.h"

using namespace std;

Map::Map(int w, int h)
{
    if (w < 1 || h < 1)
    {
        width = 1;
        height = 1;
    }
    else
    {
        width = w;
        height = h;
    }
    lights = new ObjectList(false);
    rows = new ObjectList*[height];
    columns = new ObjectList*[width];
    for (int i = 0; i < height; i++)
    {
        rows[i] = new ObjectList(false);
    }
    for (int i = 0; i < width; i++)
    {
        columns[i] = new ObjectList(true);
    }
}
Map::~Map()
{
}
void Map::add(Object* obj)
{
    rows[obj->getCoord(true)]->add(obj);
    columns[obj->getCoord(false)]->add(obj);
}
string Map::print()
{
    string output = "";
    for (int i = 0; i < height; i++)
    {
        output += rows[i]->print();
        output += "\n";
    }
    return output;
}
void Map::addLight(Object* obj)
{
    lights->add(obj);
}
Object* Map::getAt(int x, int y)
{
    Object* temp = rows[y]->iterate();
    while (temp != NULL)
    {
        if (temp->getCoord(false) == x)
            return temp;
        temp = rows[y]->iterate();
    }
    rows[y]->reset();
    return NULL;
}
void Map::resetEnvironment()
{
    for (int i = 0; i < height; i++)
    {
        rows[i]->reset();
        Object* temp = rows[i]->iterate();
        while (temp != NULL)
        {
            temp->update();
            temp = rows[i]->iterate();
        }
    }
}
void Map::updateEnvironment()
{
    lights->reset();
    Object* temp = lights->iterate();
    while (temp != NULL)
    {
        temp->update();
        temp = lights->iterate();
    }
}
