#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event
{
private:
    std::string name;
    time_t start_time;
    time_t end_time;
    bool check = false;

public:
    Event(std::string NAME, time_t START, time_t END);
    ~Event();
    std::string get_name() const;
    time_t get_start() const;
    time_t get_end() const;
    void set_check();
};

#endif