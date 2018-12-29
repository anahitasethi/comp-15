/*****************************
 * Anahita Sethi 
 * BinarySearchTree.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Implementation for BST class.
 * Inherits from BinaryTree class.
 *
 * Beyonce also wants you to be a SURVIVOR.
 *
 * You thought you'd be stressed but you're chillin'.
 ******************************/ 

#include <cstddef>
#include <cstdio> 
#include <stdio.h> 
#include <iostream> 
#include <algorithm> 
#include "BinarySearchTree.h"

/* Member function definitions */ 

//Default constructor
//Best practice is to include one 
BinarySearchTree::BinarySearchTree()
{

}

// Destructor requires no action, base class handles it
BinarySearchTree::~BinarySearchTree()
{

}

//Copy constructor 
//Makes recursive call to copy_tree
BinarySearchTree::BinarySearchTree(const BinarySearchTree& bst)
{
    BinaryNode *node = new BinaryNode; 
    root = node; 

    if (bst.root == NULL)
    {
        root = NULL; 
    }
    else
    {
        copy_tree(root, bst.root); 
    }
}

//Assignment operator 
//Begins by destroying root 
//Makes recursive call to copy_tree 
BinarySearchTree & BinarySearchTree::operator = (const BinarySearchTree &bst)
{
    destroy(root);
    if (bst.root == NULL)
    {
        root = NULL; 
    }
    else 
    {
        copy_tree(root,bst.root); 
    }
    return *this; 
}

//Function name: copy_tree
//Parameters: Reference to Binary Node pointer and Binary Node pointer
//Returns: void
//Does: Makes deep copy of tree by traversing through left and right subtrees 
void BinarySearchTree::copy_tree(BinaryNode *&to_copy, BinaryNode *source)
{
    if (source == NULL)
    {
        to_copy = NULL; 
    }
    else 
    {
        to_copy = new BinaryNode; 
        to_copy->info = source->info; 
        copy_tree(to_copy->left, source->left); 
        copy_tree(to_copy->right, source->right); 
    }
}

//Function name: find_item, const 
//Parameters: Reference to TreeItem and reference to bool 
//Returns: void
//Does: calls wrapper function to find item in binary 
//      search tree recursively 
void BinarySearchTree::find_item(TreeItem &item, bool &found) const 
{
    find_bst(root, item, found); 
}

// Function to insert into a BST
// Throws exception if full
// Calls wrapper function for recursion
void BinarySearchTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}

//Function name: remove_item
//Parameters: TreeItem
//Returns: void
//Does: Checks for empty tree
//      Throws empty tree exception if returns true
//      Else calls find function
//      If item is found, calls recursive wrapper
void BinarySearchTree::remove_item(TreeItem item)
{
    bool found = false; 
    if (is_empty())
    {
        throw EmptyTree(); 
    }
    else
    {
        find_item(item,found); 
        if (found)
        {
            remove_bst(root, item); 
        }
    }
}

/* Definitions for Recursive Wrapper Functions */

//Function name: find_bst
//Parameters: Pointer to binary node, TreeItem, reference to bool
//Returns: void
//Does: Nothing if tree points to null 
//      Recursively traverses through left subtree if item is < info in tree
//      Recursively traverses through right subtree if item is > info in tree
//      Sets found equal to true if item is equal to info in tree 
//      If item is not found at all, sets found equal to false 
void find_bst(BinaryNode *tree, TreeItem item, bool &found)
{
    if (tree == NULL)
    {
        found = false; 
        return; 
    }

    else if (item < tree->info)
    {
        find_bst(tree->left, item, found);
    }

    else if (item > tree->info)
    {
        find_bst(tree->right, item, found); 
    }

    else if (item == tree->info)
    {
        found = true; 
        item = tree->info; 
        return; 
    }
    
    else
    {
        found = false;
        return; 
    }
}

//Function name: remove_bst
//Parameters: Pointer reference to Binary Node, TreeItem
//Returns:void
//Does: nothing if tree points to NULL
//      traverses through left subtree if item < info in tree
//      traverses through right subtree if item > info in tree
//      Handles deletion of leaves, one and two-child nodes 
BinaryNode* remove_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        return tree; 
    }

    else if (item < tree->info)
    {
        tree->left = remove_bst(tree->left, item); 
    }

    else if (item > tree->info)
    {
        tree->right = remove_bst(tree->right, item); 
    }

    else
    {
        //If it's a leaf 
        //Create new pointer
        //Point pointer to tree
        //Point tree to null
        //Delete placeholder pointer 
        if ((tree->left == NULL) && (tree->right == NULL))
        { 
            BinaryNode *temp = tree; 
            tree = NULL; 
            delete temp; 
        }

        //If it's a one child node
        //Create new pointer
        //Point pointer to tree
        //Point tree to right if left subtree NULL
        //Point tree to left if right subtree NULL 
        //Delete placeholder pointer 
        else if (tree->left == NULL)
        {
            BinaryNode *temp = tree; 
            tree = tree->right; 
            delete temp; 
        }
        else if (tree->right == NULL)
        {
            BinaryNode *temp = tree; 
            tree = tree->left; 
            delete temp; 
        }

        //If it's a two child node
        //Want to replace two-child deleted node
        //With largest element in left subtree
        //Call get predecessor function
        //Returns largest node in left subtree 
        //Make recursive call to traverse through left
        else
        {
            BinaryNode *temp = get_predecessor(tree->left, item); 
            tree->info = temp->info;
            tree->left = remove_bst(tree->left, temp->info);    
        }
    }  
    return tree;    
}

//Name: get_predecessor
//Parameters: Pointer to BinaryNode, reference to TreeItem
//Returns: void
//Does: Iterates through while right child is not NULL 
//      Set tree info to predecessor's info 
BinaryNode* get_predecessor(BinaryNode *tree, TreeItem &item)
{
    while (tree->right != NULL)
    {
        tree = tree->right; 
    }
    item = tree->info; 
    return tree; 
}

//Name: insert_bst
//Parameters: Pointer reference to BinaryNode, TreeItem
//Returns: void
//Does: Recursively traverses through tree to find
//      correct position to insert 
void insert_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; // this part is why pass by ref
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }
    else if (item > tree->info)   
    {
        insert_bst(tree->right, item);
    }
}


