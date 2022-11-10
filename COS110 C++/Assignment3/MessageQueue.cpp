#include "MessageQueue.h"

using namespace std;

MessageQueue::MessageQueue(int timeout)
{
    this->timeout = timeout;
    current = timeout;
    head = NULL;
    tail = NULL;
}
MessageQueue::~MessageQueue()
{
    Message* temp = head;
    while(temp != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
void MessageQueue::addMessage(Message* message)
{
    if(head == NULL)
    {
        head = message;
        tail = message;
    }
    else
    {
        tail->next = message;
        tail = message;
    }
}
string MessageQueue::print()
{
    string output = "";
    if (head != NULL)
    {
        Message* temp = head;
        while(temp != NULL)
        {
            output += temp->getText() + "\n";
            temp = temp->next;
        }
        current--;
        if(current <= 0)
        {
            Message* temp = head;
            if (head != NULL)
            {
                head = head->next;
                delete temp;
            }
            else
            {
                head = NULL;
                tail = NULL;
            }
            current = timeout;
        }
    }
    
    return output;
}