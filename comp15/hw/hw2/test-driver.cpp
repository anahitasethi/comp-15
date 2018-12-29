/* 
 * test-driver.cpp
 *
 * COMP15
 * Spring 2018
 * HW2 test file
 *
 * Make sure your code is working,
 * a little at a time.
 * Not required for your HW2, just to 
 * be helpful!
 */


#include <iostream>
#include "LinkedList.h"
using namespace std;

void test_insert(LinkedList &, int);
void test_find(LinkedList &);
void test_delete(LinkedList &, int); 
void test_make_empty(LinkedList &);
LinkedList test_copy_constructor(LinkedList);


int main()
{
    LinkedList mylist;
 
    test_insert(mylist, 1);
    test_find(mylist);
    test_delete(mylist, 0);
    test_make_empty(mylist);

    LinkedList l2 = test_copy_constructor(mylist);
    cout << l2.get_length() << endl;
    // If I get this far, the copy constructor worked.
    // Otherwise it would seg fault
    cout << "Copy constructor: SUCCESS\n"; 
    cout << "Testing complete!\n";

    return 0;
}

// Function test_insert
// Parameters: LinkedList reference, int
// Returns
// Does: creates a planet, attempts to insert
//       into the linked list. Checks if length matches
//       the given int and prints an error message if not
void test_insert(LinkedList &l, int expected_length)
{
    Planet p("Jupiter");
    l.insert_planet(p);

    if (l.get_length() == expected_length)
    {
        cout << "Insert planet: SUCCESS\n";
    }
    else
    {
        cout << "Insert planet: FAIL. After insert " 
             << "length is " << l.get_length() << endl;
    }
}

// Function test_find
// Parameters: LinkedList reference
// Returns: none
// Does: creates a planet, tries to find it in the list
//       prints success or failure
void test_find(LinkedList &l)
{
    Planet p("Jupiter");
    bool found;
    Planet p2 = l.find_planet(p, found);

    if (!found)
    {
        cout << "Find planet: FAIL\n";
    }
    else
    {
        cout << "Find planet: SUCCESS\n";
    }
}

// Function test_delete
// Parameters: LinkedList reference, int
// Returns: none
// Does: Deletes Jupiter, and compares new length
//       to the given int. Prints success or failure.
void test_delete(LinkedList &l, int expected_length)
{
    Planet p("Jupiter");
    l.delete_planet(p);
    if (l.get_length() == expected_length)
    {
        cout << "Delete planet: SUCCESS\n";
    }
    else 
    {
        cout << "Delete planet: FAIL. After delete, length is " 
             << l.get_length() << endl;
    }
}


// Function test_make_empty
// Parameters: LinkedList reference
// Returns: none
// Does: calls make_empty function and compares
//       length to 0. Reports success or failure.
void test_make_empty(LinkedList &l)
{
    l.make_empty();
    if (l.get_length() == 0)
    {
        cout << "Make empty: SUCCESS\n";
    }
    else
    {
        cout << "Make empty: FAIL. Length should be zero but is " 
             << l.get_length() << endl;
    }
}


// Function test_copy_constructor
// Parameters: LinkedList object
// Returns: LinkedList object
// Does: Nothing. If the copy constructor doesn't
//       work we'll seg fault in the driver
LinkedList test_copy_constructor(LinkedList l)
{
    return l;
}

