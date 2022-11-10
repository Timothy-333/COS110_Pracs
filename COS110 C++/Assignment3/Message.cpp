#include "Message.h"

using namespace std;

Message::Message(string text)
{
    this->text = text;
    next = NULL;
}
string Message::getText()
{
    return text;
}
