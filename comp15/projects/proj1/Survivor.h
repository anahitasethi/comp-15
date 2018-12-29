/**************************
 * Anahita Sethi
 * COMP 15
 * Project 1 
 * Survivor Header File
 **************************/ 

#include <fstream>
#include <string>
using namespace std;

#ifndef SURVIVOR_H_
#define SURVIVOR_H_

class Survivor
{
public:
	Survivor();
    Survivor(string, string, string, string, int);
    void print(ostream &);
    void generate_next_castaway(ifstream &);
    void set_name(string, string); 
    int get_age() const; 
    void set_age(int); 
    string get_first_name() const; 
    friend bool operator == (const Survivor &, const Survivor &);
    friend bool operator != (const Survivor &, const Survivor &);
    friend bool operator < (const Survivor &, const Survivor &);
	friend bool operator > (const Survivor &, const Survivor &);

private:
    string first_name; 
    string last_name; 
    string city; 
    string state; 
    int age; 
}; 

#endif