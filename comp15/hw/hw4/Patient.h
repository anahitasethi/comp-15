/**************************
 * Anahita Sethi 
 * Patient.h
 *
 * COMP15
 * Spring 2018
 *
 * Interface for a Patient
 * 
 **************************/ 

#include <string>
using namespace std;

#ifndef PATIENT_H_
#define PATIENT_H_

//Enum declaration of five priorities 
enum Priority
{
    ONE = 1,
    TWO = 2, 
    THREE = 3, 
    FOUR = 4,
    FIVE = 5
}; 

class Patient
{
public:

    //Default constructor 
    Patient();

    //Parameterized constructor 
    Patient(string, string);

    //Comparison operators 
    friend bool operator < (const Patient &, const Patient &);
    friend bool operator > (const Patient &, const Patient &);
    friend bool operator == (const Patient &, const Patient &);
   
    //Overloading operator 
    friend ostream & operator << (ostream &, const Patient &);


    Priority get_priority() const;
    int get_time() const;  
    void calculate_priority(bool, bool, double, unsigned, int, bool); 

private:
    string fname, lname;
    bool head_wound;
    bool chest_pain;
    double temp;
    unsigned pulse;
    int time_in; 
    bool is_max; 

    Priority priority;
};

#endif
