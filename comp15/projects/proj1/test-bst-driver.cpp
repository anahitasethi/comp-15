/************************************
 * Anahita Sethi 
 * test-bst-driver.cpp
 *
 * Tests BASIC functionality of the BinarySearchtree class
 * Just the stuff from starter code.
 * 
 * Write your own tests.
 *
 * Have you written some tests?
 * 
 * Now write some more tests.
 * 
 * That's not enough tests.
 * 
 * COMP15
 * Spring 2018
 *
 *************************************/

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "Survivor.h"
using namespace std;

// Test functions for the BST operations
void test_get_length(BinaryTree *, int);
void test_insert(BinaryTree *, int);
void test_preorder(BinaryTree *);
void test_inorder(BinaryTree *);
void test_postorder(BinaryTree *);
void test_get_left(BinaryTree *);
void test_get_right(BinaryTree *); 
void test_remove(BinaryTree *, int);
void test_find(BinaryTree *); 
void test_two_child(BinaryTree *);  

int main()
{
    BinaryTree *BST = new BinarySearchTree;
    test_get_length(BST, 0);
    test_two_child(BST); 
    test_insert(BST, 5);
    test_find(BST);
    test_preorder(BST);
    test_inorder(BST);
    test_postorder(BST);
    test_get_left(BST);
    test_get_right(BST); 
    test_remove(BST, 2); 
    delete BST;
}

//Function: test_two_child
//Parameters: BT pointer
//Returns void
//Does: creates instances of a root with two children
//Inserts the nodes into the tree
//Removes the root to test functionality of removing two child node 
//Removes children after test is complete 
void test_two_child(BinaryTree *bt)
{
    Survivor root("Richard", "Hatch5", "Medford", "Massachussetts", 20); 
    Survivor child1("Richard", "Hatch0", "Medford", "Massachussetts", 20); 
    Survivor child2("Richard", "Hatch8", "Medford", "Massachussetts", 20); 

    bt->insert_item(root);
    bt->insert_item(child1); 
    bt->insert_item(child2); 

    bt->remove_item(root);
    bt->inorder(cout); 

    cout << "Should remove Hatch5 (root)" << endl 
         << "If Hatch0 and Hatch 8 printed, two child remove SUCCESS!\n"; 

    bt->remove_item(child1);
    bt->remove_item(child2); 

    //This should print nothing 
    bt->inorder(cout); 
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

// Function: test_get_length
// Returns: void 
// Parameters: BT pointer, int for expected length
// Compares number of nodes to number of items in tree
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

// Function: test_find
// Parameters: BT pointer 
// Returns: void
// Does: Calls find item on a survivor in the tree
//       Also calls find on survivor not in tree to make sure
//       It's not finding things that do not exist in tree 
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

// Function: test_remove
// Parameters: BT pointer, int of expected length 
// Returns: void
// Does: Creates instances of a root, child, and a leaf
//       Calls remove on each and compares to expected output 
//       Also compares actual length to expected length 
void test_remove(BinaryTree *BT, int new_length)
{
    cout << "Before remove tree: " << endl; 
    BT->inorder(cout);
    cout << "\n"  << endl; 
    Survivor root("Richard", "Hatch1", "Medford", "Massachussetts", 20); 
    Survivor onechild("Richard", "Hatch3", "Medford", "Massachussetts", 20); 
    Survivor leaf("Richard", "Hatch5", "Medford", "Massachussetts", 20); 

    BT->remove_item(onechild);
    cout << "After first remove, should remove 3: " << endl; 
    BT->inorder(cout);
    cout << "\n"  << endl;

    BT->remove_item(leaf);
    cout << "After second remove, should remove 5: " << endl; 
    BT->inorder(cout);
    cout << "\n"  << endl; 

    BT->remove_item(root);
    cout << "After third remove, should remove 1: " << endl; 
    BT->inorder(cout);
    cout << "\n"  << endl; 
 
    cout << "Inorder traversal printed in test remove: " << endl; 
    BT->inorder(cout); 
    if (BT->get_length() == new_length)
        cout << "test remove SUCCESS\n";
    else
        cout << "test remove FAIL\n";
}

// Print a preorder traversal
void test_preorder(BinaryTree *BT)
{
    cout << "Begin preorder test.\n";
    BT->preorder(cout);
    cout << "Expected Hatches: 1 2 3 4 5\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print an inorder traversal
void test_inorder(BinaryTree *BT)
{
    cout << "Begin inorder test.\n";
    BT->inorder(cout);
    cout << "Expected Hatches: 1 2 3 4 5\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print a postorder traversal
void test_postorder(BinaryTree *BT)
{
    cout << "Begin postorder test.\n";
    BT->postorder(cout);
    cout << "Expected Hatches: 5 4 3 2 1\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// test_get_left
// Makes sure we correclty find the leftmost node
void test_get_left(BinaryTree *bt)
{
    TreeItem t = bt->get_leftmost();
    Survivor s;
    s.set_name("Richard", "Hatch1");
    if (t == s)
        cout << "test get_left SUCCESS\n";
    else
        cout << "test get_left FAIL\n";
}

// test get_right
// Makes sure we correctly find rightmost node
void test_get_right(BinaryTree *bt)
{
    TreeItem t = bt->get_rightmost(); 
    Survivor s; 
    s.set_name("Richard", "Hatch5"); 
    if (t == s)
        cout << "test get_right SUCCESS!\n";
    else 
        cout << "test get_right FAIL\n"; 
}
