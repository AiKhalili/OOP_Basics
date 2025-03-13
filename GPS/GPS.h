#ifndef GPS_H
#define GPS_H

#include <iostream>
#include <vector>
#include <utility>

class GPS
{
private:
    double latitude;
    double longitude;
    std::vector<std::pair<double, double>> history;

public:
    GPS(double lat, double lon);
    ~GPS();
    void showOnMap() const;
    void setLocation(double lat, double lon);
    void showHistory() const;
};

#endif