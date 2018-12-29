/******************
 * Anahita Sethi
 * Test Actor 
 * COMP 15
 * Homework 5
 ******************/ 

#include "Actor.h"
#include <iostream>
#include <string> 
#include <fstream>
using namespace std; 

void test_insert_movie(string, string, string); 
void test_connect(string); 
void test_operators(Actor, Actor); 

int main() 
{
	test_insert_movie("Batman", "Superman", "Spiderman"); 
	test_connect("Batman"); 
	Actor a("Ana");
	Actor b("Banana"); 
	test_operators(a, b); 
}

//Tests insert movie and in movie functions 
void test_insert_movie(string movie1, string movie2, string movie3)
{
	Actor a; 
	a.insert_movie(movie1); 
	a.insert_movie(movie2); 
	a.insert_movie(movie3); 

	bool inmovie = a.in_movie(movie1); 
	if (inmovie == true)
	{
		cerr << "Test in movie SUCCESS" << endl; 
	}

	else
	{
		cerr << "Test in movie FAIL" << endl; 
	}
}

void test_connect(string movie)
{
	Actor a1; 
	Actor a2; 
	a1.insert_movie(movie); 
	a2.insert_movie(movie); 

	movie = a1.connect(a2); 
	cerr << "Overlapping movie: " << movie << endl
		 << "If overlapping movie name is Batman, "
		 << "test connect SUCCESS" << endl; 
}

void test_operators(Actor a, Actor b)
{
	if (a == b)
	{
		cerr << "Test operators FAIL" << endl; 
	}

	else
	{
		cerr << "Test operators SUCCCESS" << endl; 
	}

	cerr << "Actor a: " << a << "Actor b: " << b << endl; 
}

