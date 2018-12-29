/**************************************
 * Anahita Sethi
 * BinaryTree.h
 *
 * Interface for base class Binary Tree
 *
 * COMP15
 * Spring 2018
 *
 * Why don't you make like a tree...
 * and get outta here.
 **************************************/ 

#include <iostream>
#include "Tree.h"
#include "Queue.h"
using namespace std;

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

class FullTree : public exception
{
public:
    const char *what () const throw() { return "Full Tree!\n"; }
};

class EmptyTree : public exception
{
public:
    const char * what() const throw() { return "Empty Tree!\n"; }
};

// Prototypes for recursive wrapper functions
void destroy(BinaryNode *&);
int count_height(BinaryNode *); 
int count_nodes(BinaryNode *);
int count_leaves(BinaryNode *); 
TreeItem return_leftmost(BinaryNode *);
TreeItem return_rightmost(BinaryNode *); 
void print_inorder(BinaryNode *, ostream &);
void print_preorder(BinaryNode *, ostream &);
void print_postorder(BinaryNode *, ostream &);
void insert_bt(BinaryNode *&, TreeItem);
void find_bt(BinaryNode *, TreeItem &, bool &);
void remove_bt(BinaryNode *&, TreeItem);
void delete_deepest(BinaryNode *&, BinaryNode *&);
int calculate_sum(BinaryNode *); 

class BinaryTree
{
public:

    //Default constructor 
    BinaryTree();
    
    // virtual destructor to ensure
    // derived class version runs first
    virtual ~BinaryTree();

    //Copy constructor
    BinaryTree(const BinaryTree &); 

    //Assignment operator 
    BinaryTree & operator = (const BinaryTree &); 

    //Called by assignment operator and copy 
    void copy_tree(BinaryNode*&, BinaryNode *); 

    // implemented in base class, and
    // inherited by all derived classes
    int get_height() const; 
    int get_length() const;
    int get_leaves() const; 
    TreeItem get_leftmost() const;
    TreeItem get_rightmost() const; 
    void inorder(ostream &) const;
    void preorder(ostream &) const;
    void postorder(ostream &) const;
    double get_average() const; 
    int get_sum() const; 
    void print_tree(ostream &) const; 
    void print_root(ostream &) const; 
    bool is_full() const; 
    bool is_empty() const; 

    // virtual function is defined in base class,
    // overridden in derived class
    virtual void insert_item(TreeItem);
    virtual void find_item(TreeItem &, bool &) const;
    virtual void remove_item(TreeItem);

protected:
    BinaryNode *root;
};

#endif
