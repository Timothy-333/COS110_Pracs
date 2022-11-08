#include "Map.h"


using namespace std;

Map::Map(int w, int h)
{
    width = w;
    height = h;
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
