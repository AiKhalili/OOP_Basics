#include "hospital.hpp"
#include <fstream>
#include <sstream>

using namespace std;

void Hospital::add(const Patient &patient)
{
    patients.reserve(100);
    patients.push_back(patient);
    cout << "Patient added successfully!\n";
}

void Hospital::show() const
{
    cout << "Here is the list if patients in the hospital :\n";
    for (size_t i = 0; i < patients.size(); i++)
    {
        cout << i + 1 << "-\t" << patients[i].get_name() << endl;
    }
}

Patient *Hospital::searchPatient(const string &name, int &index)
{
    for (size_t i = 0; i < patients.size(); i++)
    {
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
    Patient *patientToRemove = searchPatient(name, index);

    if (index >= 0 && index < patients.size())
    {
        patients.erase(patients.begin() + index);

        ofstream file("Patients.txt", ios::trunc);
        if (file.is_open())
        {
            for (const Patient &p : patients)
            {
                file << p.encryptAns() << '\n';
            }
            file.close();
        }
        cout << "Patient removed successfully!\n";
    }
    else
    {
        cout << "No patient found with the name: " << name << '\n';
    }
}

bool Hospital::isPatientExists(const string &name)
{
    for (const Patient &p : patients)
    {
        if (p.get_name() == name)
        {
            return true;
        }
    }
    return false;
}

void Hospital::load()
{
    ifstream file("Patients.txt");
    if (!file.is_open())
    {
        return;
    }

    patients.clear();
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string name, age_str, temp_str, heart_str, resp_str, bp_str, oxygen_str, sugar_str;

        getline(ss, name, '|');
        getline(ss, age_str, '|');
        getline(ss, temp_str, '|');
        getline(ss, heart_str, '|');
        getline(ss, resp_str, '|');
        getline(ss, bp_str, '|');
        getline(ss, oxygen_str, '|');
        getline(ss, sugar_str, '|');

        name = Patient::encryptDecryptString(name);
        float age = stof(Patient::encryptDecryptString(age_str));
        float temp = stof(Patient::encryptDecryptString(temp_str));
        int heartRate = stoi(Patient::encryptDecryptString(heart_str));
        int respiratoryRate = stoi(Patient::encryptDecryptString(resp_str));
        int bloodPressure = stoi(Patient::encryptDecryptString(bp_str));
        int oxygenSaturation = stoi(Patient::encryptDecryptString(oxygen_str));
        int bloodSugar = stoi(Patient::encryptDecryptString(sugar_str));

        if (!isPatientExists(name))
        {
            patients.push_back(Patient(name, age, temp, heartRate, respiratoryRate, bloodPressure, oxygenSaturation, bloodSugar, true));
        }
    }
    file.close();
    cout << "Patients records loaded successflly!\n";
}