#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
using namespace std;
class Message
{
private:
    string text;
public:
    Message* next;
    Message(string);
    string getText();
};
#endif
