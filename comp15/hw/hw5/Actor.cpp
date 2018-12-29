/************************
 * Anahita Sethi
 * COMP 15
 * Homework 5
 * Actor Implementation
 ***********************/ 

#include "Actor.h"
#include <iostream>
#include <string> 
using namespace std;

//Default constructor
Actor::Actor()
{
	name = ""; 
}

//Parameterized constructor 
Actor::Actor(string n)
{
	name = n; 
} 

//Function name: insert_movie
//Parameters: string
//Returns: void
//Does: Takes in name of movie and inserts
//		into Linked List of actors movies 	
void Actor::insert_movie(string movie)
{
	movies.insert(movie); 
}

//Function name: in_movie
//Parameters: string
//Returns:bool 
//Does: Determines if actor was in a given
//		movie - returns true if actor in movie
bool Actor::in_movie(string movie)
{
	bool found = false; 
	movie = movies.find(movie, found);

	if (found == true)
	{
		return true; 
	} 

	else
	{
		return false; 
	}
}

//Funtion name: connect
//Parameters: Actor object 
//Returns: string
//Does: Returns name of movie in which
//		actor object and argument have 
//		appeared ogether 
string Actor::connect(Actor a)
{
	//Get length of LL of movies 
	int length = movies.get_length(); 

	//Iterate through list of movies 
	for (int i = 0; i < length; i++)
	{
		string curr = ""; 
		//Set curr equal to value at that index
		curr = movies.get_value_at(i); 
		bool found; 

		//Looks for actor object at that index 
		a.movies.find(curr, found); 

		if (found == true)
		{
			return curr; 
			break; 
		}
	}

	//If actors have no movies in common
	//Returns an empty string 
	string empty = ""; 
	return empty; 
} 

//Comparison operators 
//Returns true if two actors' names are identical 
bool operator == (const Actor &a1, const Actor &a2)
{
	return (a1.name == a2.name);
}

//Returns true if two actors' names are not identical
bool operator != (const Actor &a1, const Actor &a2)
{
	return (a1.name != a2.name);
}
   
//Prints name of actor 
ostream & operator << (ostream &out, const Actor &a)
{
	out << a.name; 
	return out; 
}

template class LinkedList<string>;