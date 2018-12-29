
/********************************
 * Anahita Sethi 
 * Planet.h
 * COMP15
 * Spring 2018
 *
 * Interface for a Planet class
 *******************************/ 

#include <fstream>
#include <string>
using namespace std;

#ifndef PLANET_H_
#define PLANET_H_

class Planet
{
public:
    // Default constructor
    Planet();

    // Paramaterized constructor
    Planet(string);
    
    // Print function 
    void print(ostream &) const;

    // Comparison operators 
    friend bool operator == (const Planet &, const Planet &);
    friend bool operator != (const Planet &, const Planet&); 

private:
    string name;
};

struct NodeType
{
    Planet info;
    NodeType *next;
};

#endif
