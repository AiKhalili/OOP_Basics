#include <iostream>
#include <sstream>
#include <stdexcept>
#include "GPS.hpp"

using namespace std;

int main()
{
    double latitude, longitude;
    string input;

    cout << "Enter initial latitude and longitude in one line, separated by a space:\n";

    while (true)
    {
        getline(cin, input);
        stringstream ss(input);
        if (ss >> latitude >> longitude)
        {
            try
            {
                GPS location(latitude, longitude);
                location.showOnMap();

                while (true)
                {
                    cout << "Enter latitude and longitude (or type 'list' to see all locations, '0' to exit):\n";
                    getline(cin, input);

                    if (input == "0")
                    {
                        return 0;
                    }

                    if (input == "list")
                    {
                        location.showHistory();
                        continue;
                    }

                    stringstream ss(input);
                    if (ss >> latitude >> longitude)
                    {
                        try
                        {
                            location.setLocation(latitude, longitude);
                            location.showOnMap();
                        }
                        catch (const invalid_argument &e)
                        {
                            cerr << "Error: " << e.what() << "Try again.\n";
                        }
                    }
                    else
                    {
                        cerr << "Error: Invalid input. Please enter two numeric values.\n";
                    }
                }
            }
            catch (const invalid_argument &e)
            {
                cerr << "Error: " << e.what() << " Please enter valid initial coordinates.\n";
            }
        }
        else
        {
            cerr << "Error: Invalid input. Please enter two numeric values.\n";
        }
    }

    return 0;
}