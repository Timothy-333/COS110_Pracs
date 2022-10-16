#include "Calendar.h"
#include "Utils.h"

#include <iostream>
#include <vector>
#include <string>
int main()
{
    vector<event_data> input;
    event_data data;
    data.start = 0;
    data.end = 0;
    data.id = 0;
    data.type = "Testing";
    input.push_back(data);
    Calendar c(input);
    cout << c << endl;
    data.start = 1;
    data.end = 1;
    data.id = 1;
    data.type = "Testing2";
    input.push_back(data);
    c.createEvent(data);
    return 0;
}