#ifndef CALENDAR_H
#define CALENDAR_H

#include "Event.h"
#include <vector>

using namespace std;
class Calendar
{
private:
    Event* head;
public:
    Calendar();
    Calendar(vector<event_data>);
    Event* getUpcomingEvent(long int);
    vector<Event> filterEvents(int*, long int*, long int*, string*);
    void alterEvent(int, long int*,string*);
    void removeEvent(int);
    void createEvent(event_data data);
    void clearCalendar();
    Event* getFirstEvent();
    friend ostream& operator<<(ostream&, Calendar&);
    ~Calendar();
};

#endif // CALENDAR_H