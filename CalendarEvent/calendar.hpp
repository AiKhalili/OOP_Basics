#ifndef CALENDAR_H
#define CALENDAR_H
#include <iostream>
#include <vector>
#include "event.hpp"

class calendar
{
private:
    std::vector<Event> events;

public:
    void add_event(const Event& newEvent);
    bool find_event(const Event &newEvent);
    void refresh();
    void print();
    void clear();
    void remove_event(const std::string &name);
};

#endif