#include <iostream>
#include "event.hpp"

using namespace std;

Event::Event(std::string NAME, time_t START, time_t END) : name(NAME), start_time(START), end_time(END)
{
    if (START >= END)
    {
        throw invalid_argument("The end time must be after the start time.\n");
    }
}

Event::~Event()
{
    cout << "Event [" << name << "] deleted.\n";
}

string Event::get_name() const { return name; }

time_t Event::get_start() const { return start_time; }

time_t Event::get_end() const { return end_time; }