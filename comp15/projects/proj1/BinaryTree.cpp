/*******************************************
 * Anahita Sethi 
 * BinaryTree.cpp
 *
 * Implementation for base class BinaryTree
 * Starter code for Project 1
 * 
 * COMP15
 * Spring 2018
 *
 * What did the Binary Tree traversal get a dinner?
 *
 * The pre-fix menu!
 ********************************************/ 

#include <cstddef>
#include "BinaryTree.h"
#include "Queue.h"

/* Member function definitions */ 

// Default Constructor
// Sets root to NULL 
BinaryTree::BinaryTree()
{
    root = NULL;
}

// Destructor
// Calls function destroy on root 
BinaryTree::~BinaryTree()
{
    destroy(root);
}

//Assignment operator 
//Makes a recursive call to helper fxn copy_tree
BinaryTree & BinaryTree::operator = (const BinaryTree &bt)
{
    //Want to start with an empty tree 
    destroy(root); 
    if (bt.root == NULL)
    {
        root = NULL; 
    }
    else
    {
        copy_tree(root,bt.root); 
    }
    return *this; 
}

// Function: copy_tree
// Accepts reference to BinaryNode pointer and BinaryNode pointer
// Returns: void
// Called by assignment operator and copy constructor 
void BinaryTree::copy_tree(BinaryNode *&this_root, BinaryNode *source_root)
{
    if (source_root == NULL)
    {
        this_root = NULL; 
    }
    else
    {
        this_root = new BinaryNode; 
        this_root->info = source_root->info; 
        copy_tree(this_root->left, source_root->left); 
        copy_tree(this_root->right, source_root->right); 
    }
}

// Copy constructor 
// Makes call to copy tree function 
// If root is not NULL 
BinaryTree::BinaryTree(const BinaryTree &bt)
{
    if (bt.root == NULL)
    {
        root = NULL; 
    }

    else
    {
        copy_tree(root, bt.root); 
    }
}

// Function name: is_full
// Accepts: no parameters
// Returns: bool 
// Const function 
// Does: Tries to create a new node 
// If a new node is created, returns false
// Else, binary tree is full and returns true 
bool BinaryTree::is_full() const 
{
  try 
  {
      BinaryNode *node = new BinaryNode; 
      delete node; 
      return false; 
  }

  catch(std::bad_alloc exception)
  {
      return true; 
  }
}

// Function name: is_empty 
// Accepts: no parameters
// Returns: bool 
// Const function
// Does: Returns true if root points to NULL
// Returns false otherwise 
bool BinaryTree::is_empty() const 
{
    if(root == NULL)
    {
        return true;
    }

    else
    {
        return false; 
    }
}

//Function get_height
//Returns depth + one 
int BinaryTree::get_height() const
{
    return count_height(root); 
}

// Function get_length (const)
// Counts the total number of nodes in the tree
int BinaryTree::get_length() const
{
    return count_nodes(root);
}

// Function get_leaves (const)
// Counts total number of leaves in tree
int BinaryTree::get_leaves() const
{
    return count_leaves(root); 
}

// Inorder traversal
void BinaryTree::inorder(ostream &out) const
{
    print_inorder(root, out);
}

// preorder traversal
void BinaryTree::preorder(ostream &out) const
{
    print_preorder(root, out);
}

// postorder traversal
void BinaryTree::postorder(ostream &out) const
{
    print_postorder(root, out);
}

// Function insert_item
// Checks for fullness, throws exception if necessary
// insert item into next open slot
void BinaryTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bt(root, item);
}

// Function find_item
// finds the given item using queue as auxiliary structure
void BinaryTree::find_item(TreeItem &item, bool & found) const
{
    find_bt(root, item, found);
}

// Function remove_item
// Checks for empty tree, throws exception if necssary
// remove item, if found
void BinaryTree::remove_item(TreeItem item)
{
    if (is_empty())
        throw EmptyTree();
    else
    {    
        bool found = false;
        find_item(item, found);
        if (found)
            remove_bt(root, item);
    }
}

// Return the item at the deepest left node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_leftmost() const
{
    return return_leftmost(root);
}

// Return the item at the deepest left node
// Throws exception if tree is empty
TreeItem BinaryTree::get_rightmost() const
{
    return return_rightmost(root); 
}

//Function name: print_tree
//Parameters: reference to ostream
//Returns: void
//Does: Prints tree info by calling 
//      Survivor print function 
//      Prints height, num nodes, num leaves 
void BinaryTree::print_tree(ostream &out) const
{
    root->info.print(out); 
    out << " " << endl; 
    int height = get_height(); 
    out << "Height: " << height << endl; 
    int nodes = get_length(); 
    out << "Number of nodes: " << nodes << endl;  
    int leaves = get_leaves(); 
    out << "Number of leaves: " << leaves << endl; 
}

//Function name: print_root
//Parameters: reference to ostream 
//Returns: void
//Does: prints tree info at root by calling
//      Survivor print function 
void BinaryTree::print_root(ostream &out) const
{
    out << "Root: "; 
    root->info.print(cout); 
}

//Function name: get_sum (const)
//Parameters: none
//Returns: int
//Does: makes call to recursive wrapper
//      To calculate sum of ages 
int BinaryTree::get_sum() const
{
    return calculate_sum(root); 
}

//Function name: get_average (const)
//Parameters: none
//Returns: double 
//Does: Calculates average by getting
//      Sum of ages, calls get length to
//      get number of nodes
//      Uses C++ conversion to double 
//      And divides sum of ages by num nodes
//      Returns average value
double BinaryTree::get_average() const
{
    double average = 0;
    int age = get_sum(); 
    int nodes = get_length();  
    average = (double) age / nodes; 
    return average; 
}

/* Definitions for Recursive Wrapper Functions */

// Name: calculate_sum
// Accepts: Pointer to BinaryNode
// Returns: int
// Does: Makes call to getter in Survivor class
//      Which returns private attribute age
//      Calculates sum of current node
//      Makes recursive call to traverse through
//      Left and right subtrees
//      Returns sum 
int calculate_sum(BinaryNode *tree)
{
    if (tree == NULL)
        return 0; 
    else 
        return (tree->info.get_age() + calculate_sum(tree->left)+
                calculate_sum(tree->right));
}

// Function destroy (wrapper)
// Used by destructor and = operator
// Follows postfix order, deletes nodes one by one
void destroy(BinaryNode *&tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

//Function name: count_height
//Parameters: pointer to BinaryNode
//Returns: int
//Does: recursively gets height by comparing left and 
//      right subtrees
int count_height(BinaryNode *tree)
{
    if (tree == NULL)
    {
        return -1; 
    }

    if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 0; 
    }

    int left = count_height (tree->left); 
    int right = count_height (tree->right); 

    if (left >= right)
    {
        return (left + 1); 
    }

    else if (right > left)
    {
        return (right + 1); 
    }
return 0; 
}

//Function name: count_nodes
//Parameters: pointer to BinaryNode
//Returns: int
//Does: recursively counts the total number of nodes in the tree
int count_nodes(BinaryNode *tree)
{
    //If there are no items in tree
    //There are no nodes 
    if (tree == NULL) 
        return 0;
    else
        return count_nodes(tree->left) + count_nodes(tree->right) + 1;
}

//Function name: count_leaves
//Parameters: pointer to BinaryNode
//Returns: int
//Does: recursively counts total number of leaves in the tree
int count_leaves(BinaryNode *tree)
{
    //If there are no items in tree 
    //There are no leaves 
    if (tree == NULL)
    {
        return 0; 
    }

    //If there is one item in the tree
    //That item is a leaf 
    if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1; 
    }

    //Makes recursive calls 
    else 
    {
        return count_leaves(tree->left) + count_leaves(tree->right); 
    }

}

// Print in  order
void print_inorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_inorder(tree->left, out);
        tree->info.print(out);
        print_inorder(tree->right, out);
    }
} 

// Print in prefix order
void print_preorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        tree->info.print(out);
        print_preorder(tree->left, out);
        print_preorder(tree->right, out);
    }
} 

// Print in postfix order
void print_postorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_postorder(tree->left, out);
        print_postorder(tree->right, out);
        tree->info.print(out);
    }
}

// Function insert_bt (wrapper)
// Params: BinaryNode reference, TreeItem
// Returns: void
// Does: Finds next open spot using a queue
//       allocates a new BinaryNode and sets
//       its info to the given tree
void insert_bt(BinaryNode *&tree, TreeItem item)
{
    // enqueue and dequeue until empty
    BinaryNode *temp = NULL;
    BinaryNode *node = new BinaryNode;
    node->info = item;
    node->left = NULL;
    node->right = NULL;
    if (tree == NULL)
    {
        tree = node;
        return;
    }
    
    Queue q;
    q.enqueue(tree);
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->left != NULL)
        {
            q.enqueue(temp->left);
        }
        else
        {
            temp->left = node;
            return;
        }
        if (temp->right != NULL)
        {
            q.enqueue(temp->right);
        }
        else
        {
            temp->right = node;
            return;
        }
    }
} 

// Function find_bt (not a member function)
// Parameters: BinaryNode (root), TreeItem reference, bool reference
// Returns: void
// Does: Uses an auxiliary queue to iterate through each node
//       until the item is found. Updates the item reference with
//       the one actually found, and bool reference with true/false. 
void find_bt(BinaryNode *tree, TreeItem &item, bool &found)
{ 
    found = false;
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    while (!q.is_empty())
    {
        BinaryNode *node; 
        q.dequeue(node);
        if (node->info == item)
        {
            item = node->info;
            found = true;
            return;
        }
        if (node->left != NULL)
            q.enqueue(node->left);
        if (node->right != NULL)
            q.enqueue(node->right);
    }
}

// Function remove_bt (wrapper)
// Parameters: BinaryNode reference (root), TreeItem to remove
// Returns: void
// Does: Uses an auxiliary queue to find the deepest item
//       swaps one to delete with deepest item
//       deletes deepest item
void remove_bt(BinaryNode *&tree, TreeItem item) 
{
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    BinaryNode *deep = NULL, *keynode = NULL;

    while (!q.is_empty())
    {
        q.dequeue(deep);
        if (deep->info == item)
            keynode = deep;
        if (deep->left != NULL)
            q.enqueue(deep->left);
        if (deep->right != NULL)
            q.enqueue(deep->right);
    }

    TreeItem val = deep->info;
    delete_deepest(tree, deep);
    if (deep != keynode)
        keynode->info = val;
}

// Delete deepest node in the tree
// Helper function for remove
void delete_deepest(BinaryNode *&tree, BinaryNode *&deepnode)
{
    Queue q;
    q.enqueue(tree);

    BinaryNode *temp;
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->right != NULL)
        {
            if (temp->right->info == deepnode->info)
            {
                temp->right = NULL;
                delete deepnode;
                return;
            }
            else
                q.enqueue(temp->right);
        }
        if (temp->left != NULL)
        {
                if (temp->left->info == deepnode->info)
                {
                    temp->left = NULL;
                    delete deepnode;
                    return;
                }
                else
                    q.enqueue(temp->left);
        }
    }
}

// Function return_leftmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest left node
// Throws exception if tree is empty, it has no leftmost ndoe
TreeItem return_leftmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->left == NULL)
        return tree->info;
    else
       return return_leftmost(tree->left);
}

// Function return_rightmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest right node
// Throws exception if tree is empty, it has no rightmost ndoe
TreeItem return_rightmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree(); 
    else if (tree->right == NULL)
        return tree->info; 
    else
        return return_rightmost(tree->right); 
}