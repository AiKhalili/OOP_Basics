#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include "hospital.hpp"
#include "patient.hpp"

using namespace std;

void menue()
{
    cout << '\n';
    cout << "**************************************************\n";
    cout << "*       MEDICAL PATIENT MANAGEMENT MENU          *\n";
    cout << "**************************************************\n";
    cout << "* 0. Exist                                       *\n";
    cout << "* 1. Add a new patient                           *\n";
    cout << "* 2. Patient lists                               *\n";
    cout << "* 3. Patient lookup                              *\n";
    cout << "* 4. Remove a patient                            *\n";
    cout << "* 5. Show patient information                    *\n";
    cout << "**************************************************\n";
    cout << "Select an option to continue: ";
}

void boundary()
{
    cout << setw(50) << "_________________________________________________\n"
         << endl;
}

int getValidInt(string &num_str)
{
    int number;
    while (true)
    {
        try
        {
            for (char c : num_str)
            {
                if (!isdigit(c))
                {
                    throw invalid_argument("Input must be a number!\n");
                }
            }
            number = stoi(num_str);
            return number;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid input! " << e.what() << "Try again.\n";
            cout << "Enter again :\n";
            cin >> num_str;
        }
    }
}

float getValidFloat(string &num_str)
{
    float number;
    while (true)
    {
        try
        {
            bool hasDot = false;
            for (char c : num_str)
            {
                if (!isdigit(c))
                {
                    if (c == '.' && !hasDot)
                    {
                        hasDot = true;
                    }
                    else
                    {
                        throw invalid_argument("Input must be a floating-pointing number!\n");
                    }
                }
            }
            number = stof(num_str);
            return number;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid input! " << e.what() << "Try again.\n";
            cout << "Enter again :\n";
            cin >> num_str;
        }
    }
}

string getValidString(string &input_str)
{
    while (true)
    {
        try
        {
            for (char c : input_str)
            {
                if (!isalpha(c))
                {
                    throw invalid_argument("Input must contain only letters!\n");
                }
            }
            return input_str;
        }
        catch (const invalid_argument &e)
        {
            cout << "Invalid input! " << e.what() << "Try again.\n";
            cout << "Enter again :\n";
            cin >> input_str;
        }
    }
}

bool check(string &selection, Hospital &hospital)
{
    string name_str, age_str, temp_str, heart_str, resp_str, pre_str, oxygen_str, sugar_str;
    string name;
    float age, bodyTemperature;
    int heartRate, respiratoryRate, bloodPressure, oxygenSaturation, bloodSugar;
    int index;
    if (selection == "0")
    {
        cout << "Have a great day!\n";
        return false;
    }
    else if (selection == "1")
    {
        cout << "Enter the following information in order : \n";
        cout << "Name :\t";
        cin >> name_str;
        cin.ignore(1000, '\n');
        name = getValidString(name_str);
        cout << "Age : (Enter as decimal)\t";
        cin >> age_str;
        cin.ignore(1000, '\n');
        age = getValidFloat(age_str);
        cout << "Body temprature :\t";
        cin >> temp_str;
        cin.ignore(1000, '\n');
        bodyTemperature = getValidFloat(temp_str);
        cout << "Heart rate :\t";
        cin >> heart_str;
        cin.ignore(1000, '\n');
        heartRate = getValidInt(heart_str);
        cout << "Respiratory rate :\t";
        cin >> resp_str;
        cin.ignore(1000, '\n');
        respiratoryRate = getValidInt(resp_str);
        cout << "Blood pressure :\t";
        cin >> pre_str;
        cin.ignore(1000, '\n');
        bloodPressure = getValidInt(pre_str);
        cout << "Oxygen Saturation :\t";
        cin >> oxygen_str;
        cin.ignore(1000, '\n');
        oxygenSaturation = getValidInt(oxygen_str);
        cout << "Blood sugar :\t";
        cin >> sugar_str;
        cin.ignore(1000, '\n');
        bloodSugar = getValidInt(sugar_str);
        Patient patient(name, age, bodyTemperature, heartRate, respiratoryRate, bloodPressure, oxygenSaturation, bloodSugar);
        hospital.add(patient);
        return true;
    }
    else if (selection == "2")
    {
        boundary();
        hospital.show();
        return true;
    }
    else if (selection == "3")
    {
        cout << "Enter patient's name :\n";
        cin >> name_str;
        cin.ignore(1000, '\n');
        name = getValidString(name_str);
        hospital.searchPatient(name, index);
        return true;
    }
    else if (selection == "4")
    {
        cout << "Enter patient's name :\n";
        cin >> name_str;
        cin.ignore(1000, '\n');
        name = getValidString(name_str);
        hospital.remove(name);
        return true;
    }
    else if (selection == "5")
    {
        cout << "Enter patient's name :\n";
        cin >> name_str;
        cin.ignore(1000, '\n');
        name = getValidString(name_str);
        Patient *patient = hospital.searchPatient(name, index);
        if (patient != nullptr)
        {
            patient->display();
        }
        return true;
    }
    else
    {
        cout << "Incorrect input.\n";
        return true;
    }
}

int main()
{
    Hospital hospital;
    string input;

    while (true)
    {
        menue();
        getline(cin, input);
        if (!check(input, hospital))
        {
            return 0;
        }
    }

    return 0;
}