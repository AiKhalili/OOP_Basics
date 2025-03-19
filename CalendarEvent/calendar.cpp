#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "calendar.hpp"

using namespace std;

bool calendar::find_event(const Event &newEvent)
{
    for (const auto &event : events)
    {
        if (newEvent.get_name() == event.get_name())
        {
            cout << "The event is already on the list.\n";
            return false;
        }
        if (!(event.get_end() <= newEvent.get_start() || newEvent.get_end() <= event.get_start()))
        {
            cout << "It conflicts with event : [" << event.get_name() << "]\n";
            return false;
        }
    }
    return true;
}

void calendar::add_event(const Event &newEvent)
{
    if (find_event(newEvent))
    {
        events.reserve(100);
        events.emplace_back(newEvent);
        cout << "Event added successfully.\n";
    }
}

void calendar::refresh()
{
    time_t now = time(nullptr);
    size_t before = events.size();

    for (size_t i = 0; i < events.size();)
    {
        if (events[i].get_end() < now)
        {
            swap(events[i], events.back());
            events.back().set_check();
            events.pop_back();
        }
        else
        {
            ++i;
        }
    }

    if (events.size() < before)
    {
        cout << "Refresh completed.\n";
    }
}

void calendar::print()
{
    cout << setw(60) << "*******************************************************************\n";
    cout << "* " << setw(20) << left << "Name"
         << "* " << setw(20) << left << "Start"
         << "* " << setw(20) << left << "End"
         << "*\n";
    cout << setw(60) << "*******************************************************************\n";
    for (const auto &event : events)
    {
        time_t start_time = event.get_start();
        time_t end_time = event.get_end();
        struct tm start_tm = *localtime(&start_time);
        struct tm end_tm = *localtime(&end_time);
        char start_buffer[80], end_buffer[80];
        strftime(start_buffer, sizeof(start_buffer), "%Y-%m-%d %H:%M:%S", &start_tm);
        strftime(end_buffer, sizeof(end_buffer), "%Y-%m-%d %H:%M:%S", &end_tm);
        cout << "* " << setw(20) << left << event.get_name()
             << "* " << setw(20) << left << start_buffer
             << "* " << setw(20) << left << end_buffer
             << "*\n";
    }
    cout << setw(60) << "*******************************************************************\n";
}

void calendar::clear()
{
    for (size_t i = 0; i < events.size(); i++)
    {
        events[i].set_check();
    }
    events.clear();
    cout << "The event list has been cleared.\n";
}

void calendar::remove_event(const string &name)
{
    auto it = remove_if(events.begin(), events.end(), [&name](const Event &event)
                        { return event.get_name() == name; });

    if (it != events.end())
    {
        it->set_check();
        events.erase(it, events.end());
    }
    else
    {
        cout << "Event [" << name << "] not found.\n";
    }
}