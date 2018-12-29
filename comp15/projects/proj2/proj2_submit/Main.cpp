/********************
 * Anahita Sethi
 * COMP 15
 * Main Implementation
 * Trying again
 *********************/ 

#include "DirNode.h"
#include "Hasher.h"
#include "FSTree.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	//Check to see if command line arguments are valid
	//Only accept two arguments 
	if (argc != 2)
    {
    	cerr << "Usage: ./the_gerp directory\n"; 
        return 1; 
    }   

    //Builds the tree based on directory 
    FSTree tree(argv[1]); 
    DirNode *root = tree.get_root(); 
    Hasher h; 

	string directory = argv[1];
	directory = directory + "/";

	//Traverses through tree 
	h.traversal(root, directory);

	//Initiates query process 
	h.start_query();

	return 0;
}	
