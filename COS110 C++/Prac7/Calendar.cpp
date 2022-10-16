#include "Calendar.h"

using namespace std;

Calendar::Calendar()
{
    head = NULL;
}
Calendar::Calendar(vector<event_data> input)
{
    head = NULL;
    for(int i = 0; i < input.size(); i++)
    {
        createEvent(input[i]);
    }
}
Calendar::~Calendar()
{
    clearCalendar();
}
Event* Calendar::getUpcomingEvent(long int now)
{
    Event* temp = head;
    Event* upcoming = NULL;
    while(temp != NULL)
    {
        if(temp->start > now)
        {
            if(upcoming == NULL)
            {
                upcoming = temp;
            }
            else if(temp->start < upcoming->start)
            {
                upcoming = temp;
            }
        }
        temp = temp->next;
    }
    return upcoming;
}
vector<Event> Calendar::filterEvents(int* id, long int* start, long int* end, string* type)
{
    vector<Event> filtered;
    Event* temp = head;
    while(temp != NULL)
    {
        if((id == NULL || temp->id == *id) && (start == NULL || temp->start >= *start) && (end == NULL || temp->end <= *end) && (type == NULL || temp->type == *type))
        {
            filtered.push_back(*temp);
        }
        temp = temp->next;
    }
    return filtered;
}
void Calendar::alterEvent(int id, long int* end, string* type)
{
    Event* temp = head;
    while(temp != NULL)
    {
        if(temp->id == id)
        {
            if(end != NULL)
            {
                temp->end = *end;
            }
            if(type != NULL)
            {
                temp->type = *type;
            }
        }
        temp = temp->next;
    }
}
void Calendar::removeEvent(int id)
{
    Event* temp = head;
    Event* prev = NULL;
    while(temp != NULL)
    {
        if(temp->id == id)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else if(temp->next == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void Calendar::createEvent(event_data data)
{
    Event* temp = new Event(data.start, data.end, data.id, data.type);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Event* prev = NULL;
        Event* curr = head;
        while(curr != NULL)
        {
            if(curr->start > temp->start)
            {
                if(prev == NULL)
                {
                    temp->next = curr;
                    head = temp;
                }
                else
                {
                    temp->next = curr;
                    prev->next = temp;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = temp;
    }
}
void Calendar::clearCalendar()
{
    Event* temp = head;
    while(temp != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
Event* Calendar::getFirstEvent()
{
    return head;
}
ostream& operator<<(ostream& out, Calendar& c)
{
    int counter = 0;
    Event* temp = c.head;
    while(temp != NULL)
    {
        out << counter++ << ": " << *temp << endl;
        temp = temp->next;
    }
    return out;
}