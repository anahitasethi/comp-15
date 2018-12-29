/**********************
* Anahita Sethi
* COMP 15
* Project 1
* Tree Class
***********************/ 

#include "Survivor.h"

#ifndef TREE_H_
#define TREE_H_

//TreeItem tied to Survivor 
typedef Survivor TreeItem; 

struct BinaryNode
{
    TreeItem info; 
    BinaryNode *left;
    BinaryNode *right;
};

#endif
