/* 
 * test-stack.cpp
 *
 * COMP15
 * Spring 2018
 * Mini driver to test functions of the 
 * stack class.
 * 
 * What did C++ say to C?
 *
 * You have no class.
 * 
 */

#include <iostream>
#include "Stack.h"
using namespace std;

void test_push(Stack &, int);
void test_top(Stack &);
void test_pop(Stack &);
void test_make_empty(Stack &);

int main()
{
    Stack s;
    test_push(s, 1);
    test_push(s, 2);
    test_top(s);
    test_pop(s);
    test_make_empty(s);
    //test_exceptions();
    return 0;
}

// Function test_push
// Parameters: Stack reference, int
// Returns: none
// Does: Pushes an element on the stack and
//       compares  new size to expected size.
//       Prints success or failure.
void test_push(Stack &s, int expected_size)
{
    s.push(3.5);
    if (s.get_size() == expected_size)
        cout << "Test push: SUCCESS\n";
    else
    {
        cout << "Test push: FAIL.\n";
        cout << "Expected size after push: " << expected_size << endl;
        cout << "Actual size after push: " << s.get_size() << endl;
    }
}

// Function test_top
// Parameters: Stack reference
// Returns: none
// Does: Calls top, and compares to see if
//       the stack's size changed.
//       Prints success or failure.
void test_top(Stack &s)
{
    int old_size = s.get_size();
    double t = s.top();
    if (s.get_size() == old_size)
        cout << "Test top: SUCCESS\n";
    else
    {
        cout << "Test top: FAIL\n";
        cout << "Expected size after top: " << old_size << endl;
        cout << "Actual size after top: " << s.get_size() << endl;
    }
}

// Function test_pop
// Parameters: Stack reference
// Returns: none
// Does: Calls pop, and checks to see if the size got
//       smaller by 1. Prints success or failure.
void test_pop(Stack &s)
{
    int old_size = s.get_size();
    s.pop();
    if (s.get_size() == (old_size-1))
        cout << "Test pop: SUCCESS\n";
    else
    {
        cout << "Test pop: FAIL\n";
        cout << "Expected size after pop: " << old_size - 1 << endl;
        cout << "Actual size after pop: " << s.get_size() << endl;
    }
}

// Function test_make_empty
// Parameters: Stack reference
// Returns: none
// Does: Calls make empty, and checks to see if
//      stack is actually empty. prints success or failure.
void test_make_empty(Stack &s)
{
    s.make_empty();
    if (s.get_size() == 0)
    {
        cout << "Test make empty: SUCCESS\n";
    }
    else
    {
        cout << "Test make empty: FAIL\n";
        cout << "Size after make empty: " << s.get_size() << endl;
    }
}


