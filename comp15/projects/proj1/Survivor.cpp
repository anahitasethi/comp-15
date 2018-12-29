/**************************
 * Anahita Sethi
 * COMP 15
 * Project 1
 * Survivor Implementation
 **************************/ 

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Survivor.h"
using namespace std;

//Default constructor
Survivor::Survivor()
{
    first_name = ""; 
    last_name = ""; 
    city = "";
    state = ""; 
    age = 0; 
}

//Parameterized constructor
Survivor::Survivor(string first, string last, string c, string s, int a)
{
	first_name = first; 
	last_name = last; 
	city = c; 
	state = s; 
	age = a; 
}

//Function name: get_age (const)
//Parameters: none
//Returns: integer
//Does: Gives access to private attribute age 
int Survivor::get_age() const 
{
	return age; 
}

void Survivor::set_age(int age_param)
{
	age = age_param; 
}

//Returns private attribute first name
//Will need this so not to read -1 sentinel 
string Survivor::get_first_name() const
{
	return first_name; 
}


//Function name: print
//Parameters: reference to ostream
//Returns:void
//Does: prints survivor info: first and last name,
//		hometown, state, and age 
void Survivor::print(ostream& out)
{
	out << first_name << " " << last_name << endl
			<< "hometown: " << city << ", " << state << endl
			<< "age: " << age << endl; 
}

//Function name: generate_next_castaway
//Parameters: reference to ifstream
//Returns: void
//Does: reads in input from file to variables 
void Survivor::generate_next_castaway(ifstream &infile)
{ 
		infile >> first_name; 
		infile >> last_name; 
		infile >> city; 
		infile >> state; 
		infile >> age;  
}

//Function name: set_name
//Parameters: string, string
//Returns: void
//Does: Sets name of survivors to given strings 
//Used in the test driver 
void Survivor::set_name(string fname1, string lname1)
{
	first_name = fname1; 
	last_name = lname1; 
} 

//Overloading operators
//Compare last names of survivors
//If survivors are equal, compare first names
//If first names are equal, return true
//Returns bool true or false 
bool operator == (const Survivor &s1, const Survivor &s2)
{
	if (s1.last_name == s2.last_name)
	{
		if (s1.first_name == s2.first_name)
		{
			return (s1.last_name == s2.last_name); 
		}
		else
		{
			return false; 
		}
	}

	else
	{
		return false; 
	}
}

bool operator != (const Survivor &s1, const Survivor &s2)
{
	if (s1.last_name != s2.last_name)
	{
		return (s1.last_name!= s2.last_name); 
	}

	else
	{
		return false; 
	}
}

bool operator < (const Survivor &s1, const Survivor &s2)
{
	if (s1.last_name < s2.last_name)
	{
		return true; 
	}

	else
	{
		return false; 
	}
}

bool operator > (const Survivor &s1, const Survivor &s2)
{
	if (s1.last_name > s2.last_name)
	{
		return true; 
	}

	else
	{
		return false; 
	}
}