#include "Event.h"

using namespace std;

Event::Event(long int start, long int end, int id, string type)
{
    this->start = start;
    this->end = end;
    this->id = id;
    this->type = type;
    this->next = NULL;
}
Event::~Event()
{
}
ostream& operator<<(ostream& out, Event& e)
{
    out << e.type << " " << unix_to_string(e.start) << "->" << unix_to_string(e.end);
    return out;
}