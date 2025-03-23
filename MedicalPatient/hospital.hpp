#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "patient.hpp"
#include <iostream>
#include <vector>

class Hospital
{
private:
    std::vector<Patient> patients;

public:
    void add(const Patient &patient);
    void show() const;
    Patient *searchPatient(const std::string &name, int &index);
    void remove(const std::string &name);
    void load();
    bool isPatientExists(const std::string &name);
};

#endif