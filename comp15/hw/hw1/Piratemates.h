/******************
* Anahita Sethi
* COMP 15
* Homework 1 
* Pirate Mates file
*******************/

#include <fstream>
#include <string>
#include "Pirate.h" 
#include "ArrayList.h" 

using namespace std;

#ifndef PIRATEMATES_H_
#define PIRATEMATES_H_
 

//Defines struct PirateMates
struct PirateMates
{
	// Pirate object
	Pirate pirate; 
	// ArrayList with pirate mates 
	ArrayList mates; 
}; 

