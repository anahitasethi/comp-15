/*******************************
 * Anahita Sethi 
 * test-min-heap.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Basic operations to test out 
 * the MinHeap class
 *******************************/ 

#include <iostream>
#include "MinHeap.h"
using namespace std;

void test_insert(Heap<int> *);
void test_extract(Heap<int> *);
void test_empty_heap(Heap<int> *);

int main()
{
    Heap<int> *min = new MinHeap<int>;
    test_insert(min);
    test_extract(min);
    test_empty_heap(min);

    delete min;
    return 0;
}

void test_insert(Heap<int> *min)
{
    int result;

    try
    {
        min->insert_item(5);
    }
    catch (FullHeap exception)
    {
        cout << "Insert FAIL\n";
        cout << exception.what() << endl;
        return;
    }

    try
    {
        result = min->get_value_at(0);
    }
    catch (EmptyHeap exception)
    {
        cout << "Insert FAIL\n";
        cout << exception.what() << endl;
        return;
    }

    if (result == 5)
        cout << "Test insert (one node) SUCCESS\n";
    else
        cout << "Test insert (one node) FAIL\n";

    min->insert_item(5);

    if (min->get_value_at(0) == 5 && min->get_value_at(1) == 5)
        cout << "Test insert (duplicate) SUCCESS\n";
    else
        cout << "Test insert (duplicate) FAIL\n";

    min->insert_item(6);
    min->insert_item(3);
    min->insert_item(7);

    if (min->get_value_at(0) == 3)
        cout << "Test insert (5 nodes, index 0) SUCCESS\n";
    else
        cout << "Test insert (5 nodes, index 0) FAIL\n";

    if (min->get_value_at(1) == 5)
        cout << "Test insert (5 nodes, index 1) SUCCESS\n";
    else
        cout << "Test insert (5 nodes, index 1) FAIL\n";

    if (min->get_value_at(2) == 6)
        cout << "Test insert (5 nodes, index 2) SUCCESS\n";
    else
        cout << "Test insert (5 nodes, index 2) FAIL\n";

    if (min->get_value_at(3) == 5)
        cout << "Test insert (5 nodes, index 3) SUCCESS\n";
    else
        cout << "Test insert (5 nodes, index 3) FAIL\n";

    if (min->get_value_at(4) == 7)
        cout << "Test insert (5 nodes, index 4) SUCCESS\n";
    else
        cout << "Test insert (5 nodes, index 4) FAIL\n";
}

void test_extract(Heap<int> *min)
{
    int extracted;
    try
    { 
        extracted = min->extract();
    }
    catch (EmptyHeap exception)
    {
        cout << "Test extract FAIL\n";
        cout << exception.what() << endl;
        return;
    }

    if (extracted == 3)
        cout << "First extract SUCCESSS\n";
    else
    {
        cout << "First extract FAIL\n";
        cout << "Expected 3, extracted " << extracted << endl;
    }

    if (min->extract() == 5)
        cout << "Second extract SUCCESS\n";
    else
        cout << "Second extract FAIL\n";

    if (min->extract() == 5)
        cout << "Third extract SUCCESS\n";
    else
        cout << "Third extract FAIL\n";

    if (min->extract() == 6)
        cout << "Fourth extract SUCCESS\n";
    else
        cout << "Fourth extract FAIL\n";

    if (min->extract() == 7)
        cout << "Fifth extract SUCCESS\n";
    else
        cout << "Fifth extract FAIL\n";
}

void test_empty_heap(Heap<int> *min)
{
    try
    {
        min->extract();
        cout << "Test empty FAIL\n";
    }
    catch (EmptyHeap exception)
    {
        cout << "Test empty SUCCESS\n";
    }
}



