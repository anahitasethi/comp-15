/****************************************
 * Anahita Sethi 
 * test-bt-driver.cpp
 *
 * Some BASIC functionality testing
 * on the Binary Tree class.
 * 
 * It can lull you into a false sense of
 * security, though. 
 *
 * Don't fall for it!
 * 
 * Write more testing code!
 * 
 * WILLLLSOOOOONNNNNN!!!!!
 *
 * COMP15
 * Spring 2018
 *
 ***************************************/ 

#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Survivor.h"
using namespace std;

// Test functions for the BT operations
void test_get_length(BinaryTree *, int);
void test_insert(BinaryTree *, int);
void test_preorder(BinaryTree *);
void test_inorder(BinaryTree *);
void test_postorder(BinaryTree *);
void test_find(BinaryTree *);
void test_remove(BinaryTree *, int);
void test_get_left(BinaryTree *);
void test_is_empty(); 
void test_get_right(BinaryTree *);
void test_leaves(BinaryTree *); 
void test_height(BinaryTree *);
void test_print(BinaryTree *); 
void test_print_root(BinaryTree *); 
BinaryTree test_copy_constructor(BinaryTree *); 
void test_average(BinaryTree *bt); 
void remove_all(BinaryTree *bt); 
//void test_find_in_empty(); 

int main()
{
    BinaryTree *BT = new BinaryTree;
    test_get_length(BT, 0);
    test_insert(BT, 5);
    test_print(BT); 
    test_print_root(BT); 
    test_get_right(BT); 
    test_leaves(BT); 
    test_height(BT); 
    test_preorder(BT);
    test_inorder(BT);
    test_postorder(BT);
    test_find(BT);    
    test_remove(BT, 2);
    test_get_length(BT, 2); 
    test_get_left(BT);
    test_is_empty(); 
    test_copy_constructor(BT); 
    test_average(BT); 
    remove_all(BT); 
    //test_find_in_empty(); 

    delete BT;
}

// Function test_get_length
// Parameters: BT pointer, int for expected length
// Returns: void 
// Does: compares number of nodes in tree to 
//       expected number of nodes 
void test_get_length(BinaryTree *bt, int num_items)
{
    if (bt->get_length() == num_items)
    { 
        cout << "test get length SUCCESS!\n";
    }
    else
    {
        cout << "test get length FAIL\n";
    }
}

//Function: test_average
//Parameters: pointer to BinaryTree
//Returns: void 
//Does: Gets average age from tree
//Compares it to expected average
void test_average(BinaryTree *bt)
{
    Survivor one("Richard", "Hatch1", "Medford", "MA", 20), 
        two("Tom", "Hanks", "Medford", "MA", 25),
        three("Anahita", "Sethi", "Medford", "MA", 65); 

    one.set_age(20);
    two.set_age(25);
    three.set_age(65); 

    bt->insert_item(one);
    bt->insert_item(two);
    bt->insert_item(three); 

    double average = bt->get_average(); 
    cout << "Average: " << average << endl; 

    //Hatch2 and 4 still in tree, ages 20 and new survivors added
    //Divided by total nodes gives average of 30  
    cout << "Expected average: 30" << endl
         << "If it matches, SUCCESS!\n"; 

    bt->remove_item(one);
    bt->remove_item(two);
    bt->remove_item(three);
}

// Function test_insert
// Parameters: BT pointer, int for # of inserts
// Returns void
// Does: prints success if all the inserts worked
void test_insert(BinaryTree *bt, int num_items)
{
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt->insert_item(vives[i]);
    }
    if (bt->get_length() == num_items)
    {
        cout << "test insert SUCCESS!\n";
    }
    else
    {
        cout << "test insert FAIL\n";
    }
    delete []vives;
}

//Function: test_print
//Paramaters: BT pointer 
//Returns: void
//Does: Prints tree so that it can be compared
//      To expected tree 
void test_print(BinaryTree *bt)
{
    bt->print_tree(cout); 
    cout << "Expected output: " << endl
         << "Root: Richard Hatch1" << endl
         << "hometown: Medford, Massachussetts" << endl
         << "age: 20" << endl 
         << "Height: 2" << endl
         << "Nodes: 5" << endl
         << "Leaves: 3" << endl; 
}

//Function: test_print
//Paramaters: BT pointer 
//Returns: void
//Does: Prints root so that it can be compared
//      To expected root 
void  test_print_root(BinaryTree *bt)
{
    bt->print_root(cout); 
    cout << "Expected output: " << endl
         << "Root: Richard Hatch1" << endl
         << "hometown: Medford, Massachussetts" << endl
         << "age: 20" << endl; 
}

//Function: test_leaves
//Paramaters: BT pointer 
//Returns: void
//Does: Compares number of leaves to 
//      Expected number of leaves 
void test_leaves(BinaryTree *bt)
{
    int leaves = bt->get_leaves(); 
    //Expected number of leaves is 3 
    if (leaves == 3)
    {
        cout << "test get_leaves SUCCESS\n"; 
    }
    else
    {
        cout << "test get_leaves FAIL\n"; 
    }
}

//Function: test_height
//Paramaters: BT pointer 
//Returns: void
//Does: Compares height to 
//      Expected height 
void test_height(BinaryTree *bt)
{
    int height = bt->get_height(); 
    //Expected height is 2
    if (height == 2)
    {
        cout << "test get_height SUCCESS\n"; 
    }
    else
    {
        cout << "test get_height FAIL\n"; 
    }
}

// Function test_find
// Attempts to find an existing and a
// non-existing item
void test_find(BinaryTree *BT)
{
    Survivor there("Richard", "Hatch1", "Medford", "Massachussetts", 20), 
        notthere("Tom", "Hanks", "Medford", "MA", 25);
    bool found;
    BT->find_item(there, found);

    if (found)
        cout << "test find (existing item): SUCCESS\n";
    else
        cout << "test find (existing item): FAIL\n";

    BT->find_item(notthere, found);
    if (!found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";
}

/* 
void test_find_in_empty()
{
    bool found; 
    Survivor tofind("Richard", "Hatch1", "Medford", "MA", 20); 
    BinaryTree *tree = new BinaryTree; 
    tree->find_item(tofind, found); 

    if (found)
    {
        cout << "Found item in empty tree" << endl; 
    }

    else
    {
        cout << "Did not find item in empty tree" << endl; 
    }
}
*/ 

// Print a preorder traversal
void test_preorder(BinaryTree *BT)
{
    cout << "Begin preorder test.\n";
    BT->preorder(cout);
    cout << "Expected Hatches: 1 2 4 5 3\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print an inorder traversal
void test_inorder(BinaryTree *BT)
{
    cout << "Begin inorder test.\n";
    BT->inorder(cout);
    cout << "Expected Hatches: 4 2 5 1 3\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print a postorder traversal
void test_postorder(BinaryTree *BT)
{
    cout << "Begin postorder test.\n";
    BT->postorder(cout);
    cout << "Expected Hatches: 4 5 2 3 1\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

//Function: test_is_empty
//Paramaters: none
//Returns: void
//Does: Create new binary tree, not populated with anything yet
//      If tree returns true for is_empty, fxn works 
void test_is_empty()
{
    BinaryTree *tree = new BinaryTree; 
    if (tree->is_empty() == true)
    {
        cout << "test empty SUCCESS\n"; 
    }
    else
    {
        cout << "test empty FAIL\n"; 
    }
    delete tree; 
}

//Function: test_copy_constructor
//Paramaters: BT pointer 
//Returns: BinaryTree object 
//Does: Invokes copy constructor by creating new instance
//      Of binary tree object which creates deep copy
//      Compares length to length of new instance 
BinaryTree test_copy_constructor(BinaryTree *bt)
{
    BinaryTree BT2(*bt); 

    //Expected length because it's making a copy 
    int length = BT2.get_length(); 
    if (length == 2)
    {
        cout << "test copy constructor SUCCESS!\n"; 
    }
    else
    {
        cout << "test copy constructor FAIL!\n"; 
    } 
    return *bt; 
}

// Function: test remove
// Remove a leaf node, a root, a node in the deepest leaf
// and a node that's already been removed
void test_remove(BinaryTree *BT, int new_length)
{
    Survivor leaf("Richard", "Hatch3", "Medford", "Massachussetts", 20), 
        root("Richard", "Hatch1", "Medford", "Massachussetts", 20),
        deepest("Richard", "Hatch5", "Medford", "Massachussetts", 20),
        alreadyremoved("Richard", "Hatch5", "Medford", "Massachussetts", 20);

    BT->remove_item(leaf);
    BT->remove_item(root);
    BT->remove_item(deepest);
    BT->remove_item(alreadyremoved);

    if (BT->get_length() == new_length)
        cout << "test remove SUCCESS\n";
    else
        cout << "test remove FAIL\n";
}

//Prevents memory leak 
void remove_all(BinaryTree *bt)
{
    Survivor intree("Richard", "Hatch2", "Medford", "Massachussetts", 20), 
        intree2("Richard", "Hatch4", "Medford", "Massachussetts", 20);
    bt->remove_item(intree); 
    bt->remove_item(intree2); 
}

// test_get_left
// Makes sure we correctly find the leftmost node
void test_get_left(BinaryTree *bt)
{
    TreeItem t = bt->get_leftmost();
    Survivor s;
    s.set_name("Richard", "Hatch2");
    if (t == s)
        cout << "test get_left SUCCESS\n";
    else
        cout << "test get_left FAIL\n";
}

//Function: test_get_right
//Paramaters: BT pointer 
//Returns: void
//Does: Gets rightmost node and compares to
//      Expected rightmost node 
void test_get_right(BinaryTree *bt)
{
    TreeItem t = bt->get_rightmost();
    Survivor s;
    s.set_name("Richard", "Hatch3");
    if (t == s)
        cout << "test get_right SUCCESS\n";
    else
        cout << "test get_right FAIL\n";
}

