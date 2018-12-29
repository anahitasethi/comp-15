/********************
 * Anahita Sethi
 * COMP 15
 * Homework 5
 * Actor Header File
 ********************/ 

#include "LinkedList.h"
#include <iostream>
#include <ostream> 
#include <string> 
using namespace std; 

#ifndef ACTOR_H_
#define ACTOR_H_

class Actor
{
	
public:
	//Default constructor 
	Actor(); 
	
	//Parameterized constructor 
	Actor(string); 

	//Takes in movie name and inserts into movie list 
	void insert_movie(string); 

	//Determines if actor was in given movie 
	bool in_movie(string); 

	//Returns name of movie actors have in common 
	string connect(Actor); 

	//Overloading comparison operators 
	friend bool operator == (const Actor &, const Actor &);
    friend bool operator != (const Actor &, const Actor &);
   
    //Prints name of actor 
    friend ostream & operator << (ostream &, const Actor &);

private:
	string name; 
	LinkedList<string> movies; 
}; 

#endif 