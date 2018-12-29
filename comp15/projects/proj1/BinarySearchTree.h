/* ******************************
 * Anahita Sethi 
 * BinarySearchTree.h
 *
 * Interface for derived class BST
 * Inherits from Binary Tree
 *
 * Gloria Gaynor wants you to 
 * SURVIVE this project. 
 *
 * Don't be afraid.
 * 
 * Don't be petrified.
 * 
 * Come back from outer space.
 ********************************/ 

#include <iostream> 
#include <algorithm> 
#include "BinaryTree.h"

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

// Prototypes for recursive wrapper functions
void insert_bst(BinaryNode *&, TreeItem);
void find_bst(BinaryNode *, TreeItem, bool &); 
BinaryNode* remove_bst(BinaryNode *&, TreeItem);
BinaryNode* get_predecessor(BinaryNode *, TreeItem &); 
void find_helper(BinaryNode *, TreeItem, bool &); 

//Inherited from BinaryTree 
class BinarySearchTree : public BinaryTree
{

public:

    //Default constructor 
    BinarySearchTree();

    // BT has a virtual destructor
    // so we write our own for BST
    ~BinarySearchTree();

    //Copy constructor 
    BinarySearchTree(const BinarySearchTree &); 

    //Assignment operator 
    BinarySearchTree & operator = (const BinarySearchTree &); 

    //overridden from BinaryTree
    void remove_item(TreeItem); 
    void find_item(TreeItem &, bool &) const; 
    void insert_item(TreeItem);

    // Called by copy cstr and assignment operator 
    void copy_tree(BinaryNode *&, BinaryNode*); 
};

#endif
