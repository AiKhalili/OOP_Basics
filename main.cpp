#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "calendar.hpp"
#include "event.hpp"

using namespace std;

time_t stringToTimeT(const string &timeStr)
{
    struct tm tmStruct = {};
    istringstream ss(timeStr);
    ss >> get_time(&tmStruct, "%Y-%m-%d %H:%M:%S");
    if (ss.fail())
    {
        throw runtime_error("Invalid time format.\n");
    }
    time_t result = mktime(&tmStruct);
    if(result == -1){
        throw runtime_error("Invalid time value.\n");
    }
    return result;
}

void toLower(string *str)
{
    for (int i = 0; i < str->size(); i++)
    {
        (*str)[i] = tolower((*str)[i]);
    }
}

void menue()
{
    cout << "\n";
    cout << "****************************************\n";
    cout << "*          EVENT MANAGEMENT MENU       *\n";
    cout << "****************************************\n";
    cout << "* 1. Add an event to the list          *\n";
    cout << "* 2. Print the event list              *\n";
    cout << "* 3. Reload the list of events         *\n";
    cout << "* 4. Empty the event list              *\n";
    cout << "* 5. Delete the selected event         *\n";
    cout << "****************************************\n";
    cout << "Select an option to continue: ";
}

void boundary()
{
    cout << setw(50) << "_________________________________________________" << endl;
}

void find(string selection , calendar& check)
{
    if (selection == "1") // Add
    {
        string name, start, end;
        cout << "Enter the new event's name :\n";
        cin >> name;
        cin.ignore(1000,'\n');
        toLower(&name);
        cout << "Enter the start time(with this format : YYYY-MM-DD HH:MM:SS)\n";
        getline(cin, start);
        cout << "Enter the end time(with this format : YYYY-MM-DD HH:MM:SS)\n";
        getline(cin, end);
        try
        {
            time_t start_t = stringToTimeT(start);
            time_t end_t = stringToTimeT(end);
            Event newEvent(name, start_t, end_t);
            check.add_event(move(newEvent));
        }
        catch (const exception &e)
        {
            cout << "Error : " << e.what() << '\n';
        }
    }
    else if (selection == "2")
    { // print
        check.print();
    }
    else if (selection == "3")
    { // refresh
        check.refresh();
    }
    else if (selection == "4")
    { // clear
        check.clear();
    }
    else if (selection == "5")
    { // remove
        string name;
        cout << "Enter the event name :\n";
        cin >> name;
        cin.ignore(1000,'\n');
        toLower(&name);
        check.remove_event(name);
    }
    else
    {
        cout << "Incorrect input.\n";
    }
}

int main()
{
    calendar check;
    while (true)
    {
        menue();
        string selection;
        string input;
        cin >> selection;
        cin.ignore();
        find(selection , check);

        boundary();

        cout << "Do you still want to continue ? \n"
             << "If you don't want to continue , enter 0 .\n";
        getline(cin, input);
        if (input == "0")
        {
            break;
        }
        boundary();
    }
    return 0;
}