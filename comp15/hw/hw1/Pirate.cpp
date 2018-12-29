/**********************************
 * Anahita Sethi 
 * Pirate.cpp
 * COMP15
 * Spring 2018
 *
 * Implarrrrrrmentation of a Pirate
 ***********************************/ 

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Pirate.h"
using namespace std;

int Pirate::pirate_count = 0;

//Default constructor
Pirate::Pirate()
{
    pirate_id = -1;
    name = "Cap'n Hook";
}

//Constructor
Pirate::Pirate(string n)
{
    assign_pirate_id();
    name = n;
}

//Name: print
//Returns: void
//Paramaters: reference to ostream object outfile
//Accessor function (doesn't modify data structure)
//Does: Prints pirate ID, a space, and pirate name
void Pirate::print(ostream& outfile) const
{
    //Prints pirate ID, space, and name out to a file 
    outfile << pirate_id << " " << name; 
}

void Pirate::generate_pirate_name(ifstream &infile, int range)
{
    string pname;
    int rando = rand() % range;
    int count = 0;

    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, pname))
    {
        if (count == rando)
        {
            name = pname;
            break;
        }
        count++;
    }
}

void Pirate::assign_pirate_id()
{
    pirate_id = pirate_count++;
}

bool operator == (const Pirate &p1, const Pirate &p2)
{
    return (p1.pirate_id == p2.pirate_id);
}

//Name: generate_next_pirate
//Returns: void
//Paramaters: reference to ifstream object infile 
//Does: Gets pirate name from file of pirate names
//Getline function used to get full name
void Pirate::generate_next_pirate(ifstream &infile)
{
	getline(infile, name);  
}
