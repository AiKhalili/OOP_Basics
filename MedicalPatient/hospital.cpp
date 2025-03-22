#include "hospital.hpp"

using namespace std;

void Hospital::add(const Patient &patient)
{
    patients.push_back(patient);
    cout << "Patient added successfully!\n";
}

void Hospital::show() const
{
    cout << "Here is the list if patients in the hospital :\n";
    for (size_t i = 0; i < patients.size(); i++)
    {
        Patient temp = patients[i];
        temp.encryptOrDecrypt();
        cout << i + 1 << "-\t" << patients[i].get_name() << endl;
    }
}

Patient *Hospital::searchPatient(const string &name, int &index)
{
    for (size_t i = 0; i < patients.size(); i++)
    {
        Patient temp = patients[i];
        temp.encryptOrDecrypt();
        if (patients[i].get_name() == name)
        {
            cout << "Patient found!\n";
            index = i;
            return &patients[i];
        }
    }

    cout << "No patient found with the name : " << name << '\n';
    return nullptr;
}

void Hospital::remove(const string &name)
{
    int index = -1;
    Patient *nothing = searchPatient(name, index);
    if (index >= 0 && index < patients.size())
    {
        patients.erase(patients.begin() + index);
        cout << "Patient removed successfully!\n";
    }
}