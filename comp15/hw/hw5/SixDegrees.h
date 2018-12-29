/**************************
 * Anahita Sethi
 * COMP 15
 * Homework 5
 * Six Degrees Header File
 **************************/ 

#include "Graph.h"
#include <string> 
#include <iostream>
#include <ostream>

#ifndef SIXDEGREES_H_
#define SIXDEGREES_H_

class SixDegrees
{
public:
	//Default constructor 
	SixDegrees();

	//Function to populate graph from "actors.txt"
	void populate_graph(); 

	//Function called from main, calls BFS 
	void run(istream &, ostream &); 

	//Finds and prints path from a to b  
	void BFS(Actor, Actor, ostream &); 

	//Function that handles edge of movies
	void connect_movies(Actor, int); 


private:
	//Graph object of actors 
	Graph<Actor> g; 

}; 

#endif 