/************************************************
 * Anahita Sethi 
 * main.cpp
 *
 * Driver for Six Degrees of Kevin Bacon
 *
 * COMP15
 * Spring 2018
 *
 * Fun fact: Kevin Bacon's dad is locally famous,
 * but not for acting. He's a city planner for 
 * Philadelphia, and was on the cover of TIME
 * in 1964.
 **********************************************/ 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "SixDegrees.h"

using namespace std;

void read_from_file(char *); 
 
int main(int argc, char *argv[])
{
	SixDegrees sd;

    //Read from cin and write to cout if no command line
    //arguments are provided
	if (argc == 1)
    {
     	sd.run(cin, cout);   
    }

    //Read from input file and write to cout if 1 command line
    //argument is provided 
    else if (argc == 2)
    {
    	read_from_file(argv[1]); 
    }

    //Error message to handle incorrect user input 
    else
    {
    	cerr << "Usage: ./sixdegrees or ./sixdegrees [infilename]\n"; 
        return 1; 
    }   
 
    return 0;
}

//Function name: read_from_file
//Parameters: pointer to char
//Returns: void
//Does: Opens file, calls run from file
void read_from_file(char *fname)
{
    //Open file
	SixDegrees sd; 
	ifstream infile;
    infile.open(fname);

    //Check for open file
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }

    //Call run with ifstream that reads from file
    //Write to cout 
    sd.run(infile, cout); 

    //Close file 
    infile.close(); 

}
