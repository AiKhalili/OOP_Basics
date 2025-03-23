#include "patient.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

Patient::Patient(string NAME, float AGE, float TEMP, int HEART, int RESP, int BLOODP, int OXYGEN, int SUGER)
{
    name = NAME;
    age = AGE;
    bodyTemperature = TEMP;
    heartRate = HEART;
    respiratoryRate = RESP;
    bloodPressure = BLOODP;
    oxygenSaturation = OXYGEN;
    bloodSugar = SUGER;
    validateVitals();
}

Patient::Patient(string NAME, float AGE, float TEMP, int HEART, int RESP, int BLOODP, int OXYGEN, int SUGER,bool fromFile)
{
    name = NAME;
    age = AGE;
    bodyTemperature = TEMP;
    heartRate = HEART;
    respiratoryRate = RESP;
    bloodPressure = BLOODP;
    oxygenSaturation = OXYGEN;
    bloodSugar = SUGER;
}

bool Patient::validateResp(float Age, int rate) const
{
    if (Age <= 0.1)
    {
        return (rate >= 30 && rate <= 40);
    }
    if (Age <= 0.5)
    {
        return (rate >= 25 && rate <= 40);
    }
    if (Age <= 3)
    {
        return (rate >= 20 && rate <= 30);
    }
    if (Age <= 6)
    {
        return (rate >= 18 && rate <= 25);
    }
    if (Age <= 10)
    {
        return (rate >= 17 && rate <= 23);
    }
    if (Age <= 50)
    {
        return (rate >= 15 && rate <= 18);
    }
    if (Age <= 65)
    {
        return (rate >= 18 && rate <= 25);
    }
    if (Age <= 80)
    {
        return (rate >= 12 && rate <= 28);
    }
    return (rate >= 10 && rate <= 30);
}

void Patient::validateVitals() const
{
    cout << "Checking vitals for " << name << "...\n";
    if (bodyTemperature < 36 || bodyTemperature > 37.5)
    {
        cout << "Warning : Abnormal body temperature!\n";
    }
    if (heartRate < 60 || heartRate > 100)
    {
        cout << "Warning : Abnormal heart rate!\n";
    }
    if (!validateResp(age, respiratoryRate))
    {
        cout << "Warning : Abnormal respiratoty rate for this age!\n";
    }
    if (bloodPressure < 80 || bloodPressure > 120)
    {
        cout << "Warning : Abnormal blood pressure!\n";
    }
    if (oxygenSaturation < 95 || oxygenSaturation > 100)
    {
        cout << "Warning : Abnormal oxygen level!\n";
    }
    if (bloodSugar > 100)
    {
        cout << "Warning : High blood suger level!\n";
    }
}

void Patient::display() const
{
    cout << "* Name : " << name << endl
         << "* Age : " << age << endl
         << "* Body temperature : " << bodyTemperature << " C\n"
         << "* Heart rate : " << heartRate << " bpm\n"
         << "* Blood pressure : " << bloodPressure << endl
         << "* Respiratory rate : " << respiratoryRate << endl
         << "* Oxygen saturation : " << oxygenSaturation << " %\n"
         << "* Blood suger : " << bloodSugar << "mg/dL\n";
}

string Patient::encryptDecryptString(string text)
{
    char key = 'X';
    for (char &c : text)
    {
        c ^= key;
    }
    return text;
}

string Patient::encryptAns() const
{
    stringstream ss;

    ss << encryptDecryptString(name) << '|'
       << encryptDecryptString(to_string(age)) << '|'
       << encryptDecryptString(to_string(bodyTemperature)) << '|'
       << encryptDecryptString(to_string(heartRate)) << '|'
       << encryptDecryptString(to_string(respiratoryRate)) << '|'
       << encryptDecryptString(to_string(bloodPressure)) << '|'
       << encryptDecryptString(to_string(oxygenSaturation)) << '|'
       << encryptDecryptString(to_string(bloodSugar));
   return ss.str();
}

Patient::~Patient()
{
    encryptAns();
    cout << "Data encrypted!\n";
}
 

string Patient::get_name() const { return name; }