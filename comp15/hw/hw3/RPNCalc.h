/************************
 * Anahita Sethi
 * COMP 15
 * HW 3 
 * RPN Calc Header File
 ***********************/

#include <string>
#include "Stack.h"
using namespace std; 

#ifndef RPNCALC_H_
#define RPNCALC_H_

class RPNCalc 
{
public: 
    //Default constructor
    RPNCalc();

    //Reads in inputs
    void run(); 

    //Reads in inputs from file or standard in
    void run_from(istream &in); 

    //Checks if input is an operator 
    bool is_operator(const string& input); 

    //Checks if input is a double 
    bool check_for_double(const string input, double& num); 

public:
    //Declares an object of stack class 
    Stack s; 
    //Declares a bool to quit
    bool quit; 
};

#endif