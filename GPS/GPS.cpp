#include <iostream>
#include <stdexcept>
#include "GPS.hpp"

using namespace std;

GPS::GPS(double lat, double lon)
{
    if (lat < -90.0 || lat > 90.0 || lon < -180.0 || lon > 180.0)
    {
        throw invalid_argument("Invalid GPS coordinates !\n");
    }
    latitude = lat;
    longitude = lon;
    history.push_back({lat, lon});
}

GPS::~GPS()
{
    if (!history.empty())
    {
        pair<double, double> lastLocation = history.back();
        cout << "Last known location : ( " << lastLocation.first << " , " << lastLocation.second << " )\n";
    }
}

void GPS::showOnMap() const
{
    cout << "See your location on Google Maps :\t";
    cout << "https://www.google.com/maps?q=" << latitude << "," << longitude << endl;
    cout << "____________________________________________________________________________________\n";
}

void GPS::setLocation(double lat, double lon)
{
    if (lat < -90.0 || lat > 90.0 || lon < -180.0 || lon > 180.0)
    {
        throw invalid_argument("Invalid GPS coordinates !\n");
    }
    latitude = lat;
    longitude = lon;
    history.push_back({lat, lon});
}

void GPS::showHistory() const
{
    if (history.empty())
    {
        cout << "No location stored yet!\n";
    }
    else
    {
        int count = 0;
        cout << "Location history :\n";
        for (const auto &loc : history)
        {
            cout << ++count << "-\t" << loc.first << "," << loc.second << endl;
        }
    }
}