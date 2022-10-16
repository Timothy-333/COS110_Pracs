#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Utils.h"

using namespace std;

class Event
{
public:
    long int start;
    long int end;
    int id;
    string type;
    Event* next;
    Event(long int, long int, int , string);
    ~Event();
    friend ostream& operator<<(ostream&, Event&);
};
#endif // EVENT_H