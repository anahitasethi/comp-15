/**********************
 * Anahita Sethi
 * COMP 15
 * Survivor Driver
 * Project 1 
 *********************/ 

#include <iostream> 
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath> 
#include <ctime>
#include <string>
#include "BinarySearchTree.h"
#include "Survivor.h"
using namespace std;

//Function to populate either the BT or BST 
void populate_tree(BinaryTree *, string);

int main() 
{ 
    BinaryTree *BST = new BinarySearchTree;
    BinaryTree *BT = new BinaryTree;

    //Generate random number 1 or 2 (equal chance) 
    srand(time(NULL)); 
    int random; 
    random = rand()%2+1; 

    //Populate trees with different files depending
    //on which number is generated 
    if (random == 1)
    {
        populate_tree(BT, "castaways.txt"); 
        populate_tree(BST, "stowaways.txt"); 
    }

    else if (random == 2)
    {
        populate_tree(BT, "stowaways.txt"); 
        populate_tree(BST, "castaways.txt"); 
    }

    //Get leaves in binary and binary search trees 
    int BT_leaves = BT->get_leaves(); 
    int BST_leaves = BST->get_leaves(); 

    //Round one winner is the one with less leaves 
    //Compares binary tree leaves with binary search tree 
    //Prints tree of the one with more leaves 
    if (BT_leaves <= BST_leaves)
    {
        cout << "Loser had " << BST_leaves << " leaves" << endl
             << "ROUND ONE WINNER: BT" << endl; 
        BT->print_tree(cout); 
        
        //Enters loop while there is more than one remaining survivor 
        //in the tree 
        while (BT->get_length() != 1)
        {
            //Calculate average age of castaways in tree 
            double average = BT->get_average(); 
            cout << " " << endl
                 << "Average age this round " << average << endl; 

            //Get left and rightmost nodes in tree 
            TreeItem Survivor1 = BT->get_leftmost(); 
            TreeItem Survivor2 = BT->get_rightmost(); 

            //Get age of left and righmost nodes
            int leftmost_age = Survivor1.get_age(); 
            int rightmost_age = Survivor2.get_age(); 

            //Use C++ absolute value function to calculate which age
            //Is closer to the average 
            //Vote off and remove the one that is farther away 
            if (abs (leftmost_age - average) <
                abs (rightmost_age - average))
            {
                cout << "Voted off the island: " << endl; 
                Survivor2.print(cout); 
                BT->remove_item(Survivor2); 
            }
            else if (abs (leftmost_age - average) >= 
                     abs (rightmost_age - average))
            {
                cout << "Voted off the island: " << endl; 
                Survivor1.print(cout); 
                BT->remove_item(Survivor1); 
            }
        }

        //Winner is the only node left in the tree 
        //Can use get leftmost to find this item - doesn't matter
        //Because it is now just a leaf
        //Print out the winner info 
        TreeItem winner = BT->get_leftmost(); 
        //When there is one castaway left 
        cout << endl << "WINNING SURVIVOR:" << endl; 
        winner.print(cout); 

    }

    //If number of leaves in BST tree is less than BT tree
    //Then round one winner is BST tree, which gets printed 
    else if (BST_leaves < BT_leaves)
    {
        cout << "Loser had " << BT_leaves << " leaves" << endl
             << "ROUND ONE WINNER: BST" << endl; 
        BST->print_tree(cout); 

        //Enters loop while there is more than one survivor left 
        while (BST->get_length() != 1)
        {
            //Round 2 compares avg age to leftmost and righmost avg age
            double average = BST->get_average(); 
            cout << " " << endl
                 << "Average age this round " << average << endl; 

            TreeItem Survivor1 = BST->get_leftmost(); 
            TreeItem Survivor2 = BST->get_rightmost(); 

            int leftmost_age = Survivor1.get_age(); 
            int rightmost_age = Survivor2.get_age(); 

            if (abs (leftmost_age - average) < 
                abs (rightmost_age - average))
            {
                cout << "Voted off the island: " << endl; 
                Survivor2.print(cout); 
                BST->remove_item(Survivor2); 
            }

            else if (abs (leftmost_age - average) >= 
                     abs (rightmost_age - average))
            {
                cout << "Voted off the island: " << endl; 
                Survivor1.print(cout); 
                BST->remove_item(Survivor1); 
            }
        }

        //When there is one castaway winner left 
        TreeItem winner = BT->get_leftmost(); 
        cout << endl << "WINNING SURVIVOR:" << endl; 
        winner.print(cout);  
    }

    delete BST; 
    delete BT; 

    return 0; 

}

//Function name: populate_tree
//Parameters: Pointer to Binary Tree, string 
//Returns: void
//Does: opens file for reading, generates next castaway
//      using info stored in file, inserts item into binary
//      tree then closes file 
void populate_tree(BinaryTree *bt, string filename)
{
    ifstream infile; 
    infile.open(filename); 
    if (!infile.is_open())
    {
        cout << "File could not be opened" << endl; 
        exit(1); 
    }

    while (!infile.eof())
    {
        Survivor s; 
        s.generate_next_castaway(infile); 
        if (s.get_first_name() != "-1")
        {
             bt->insert_item(s); 
        }
    }

    infile.close(); 
}