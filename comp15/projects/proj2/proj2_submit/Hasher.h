/***********************
 * Anahita Sethi
 * COMP 15
 * Project 2
 * Hasher Header File
 ***********************/ 

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set> 
#include <functional>
#include <string>
#include "FSTree.h"
#include "DirNode.h"
#ifndef HASHER_H_
#define HASHER_H_

using namespace std;
	
//Struct containing file pathway and line number of word 
struct Location
{
	string filepathway;
	int line_number;   
	//Initializes variables with parameterized constructor
	Location(string s, int i)
	{
		filepathway = s;
		line_number = i;
	};
};

//Struct containing original word and vector of words with same 
//original word
struct Word
{
	string original_word;
	vector<Location> locs;
	//Parameterized constructor 
	Word(string s, Location l)
	{
	    original_word = s;
	    locs.push_back(l);
	};
};    

//Struct containing lowercase version of word and structs of words
//with the same key 
struct Key
{
	string low_name;
	vector<Word> words;
	Key *next;
	Key(string s, vector<Word> w)
	{
	   	low_name = s;
	    words = w;
	    next = NULL;
	};
	Key(string s, Word w)
	{
	   	low_name = s;
	    words.push_back(w);
	    next = NULL;
	};
};

class Hasher
{
public:
	//Default constructor
	Hasher();

	//Destructor 
	~Hasher();

	//Deletes table
	void delete_table(int);

	//Traverses through directories to get file 
	void traversal(DirNode*, string);

	//Handles file I/O and file processing 
	void open_file(string);

	//Converts string to valid string
	string strip_nonalphanum(string);
	string strip_leading(string); 
	string strip_trailing(string); 

	//Converts string to lowercase string
	string lower(string);

	//Generates an index for the string 
	size_t hash_word(string) const;

	//Inserts items into the hashtable 
	void insert(Key *&, string, Word);

	//Inserts words when that key already exists 
	void insert_existing(Key *&, Word);

	//Expands table and makes call to rehash 
	void expand();

	//Rehashes table 
	void initialize_node(Key *, Key **);

	//Asks for user input and begins query process 
	void start_query();

	//Finds word in table and makes appropriate call 
	void search(bool, string);

	//Makes call to print depending to case sensitivity 
	bool found_word(bool, string, Key *);	

	//Prints info about words
	void print_info(vector <Location> &);


private:
	int capacity;
	int key_count;
	int file_count;
	Key** hash_table;
};

#endif

