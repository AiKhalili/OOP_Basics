#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

class Patient
{
private:
    std::string name;
    float age;
    float bodyTemperature;
    int heartRate;
    int respiratoryRate;
    int bloodPressure;
    int oxygenSaturation;
    int bloodSugar;
    bool IsEncrypt = false;

    void validateVitals() const;
    bool validateResp(float Age, int rate) const;

public:
    Patient(std::string NAME, float AGE, float TEMP, int HEART, int RESP, int BLOODP, int OXYGEN, int SUGER, bool ISENCRYPT);
    ~Patient();
    void display() const;
    std::string get_name() const;
    static std::string encryptDecryptString(std::string text);
    std::string encryptAns() const;
};
#endif