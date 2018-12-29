/************************
 * Anahita Sethi
 * COMP15
 * Homework 4 
 * Heap Implementation
 ************************/ 

#include "Heap.h"
#include "Patient.h"
#include <iostream>
using namespace std;

//Default constructor
template<class E>
Heap<E>::Heap()
{
    length = 0; 
}

//Destructor 
template<class E>
Heap<E>::~Heap()
{
}

//Function name: is_full, const
//Parameters: none
//Returns: bool
//Does: checks if length is 
//      equal to max capacity
//      returns true if it does,
//      else return false.
template<class E>
bool Heap<E>::is_full() const 
{
    if (length == MAX_CAPACITY)
    {
        return true; 
    }

    else 
    {
        return false; 
    }
}

//Function name: is_empty, const
//Parameters: none
//Returns: bool
//Does: checks if length is 
//      equal to 0 and returns true
//      else returns false 
template<class E>
bool Heap<E>::is_empty() const 
{
    if (length == 0)
    {
        return true; 
    }

    else
    {
        return false; 
    }
}

//Function name: insert_item
//Parameters: type E 
//Returns: void 
//Does: throws an exception if
//      heap is full
//      else inserts item into next
//      open slot and restores 
//      properties of heap using
//      heapify up 
template<class E>
void Heap<E>::insert_item(E item)
{
    if (is_full())
    {
        throw FullHeap(); 
    }

    else
    {
        heap[length] = item; 
        length++; 
        heapify_up(length-1); 
    }
}

//Function name: extract 
//Parameters: none
//Returns: type E
//Does: throws an exception if
//      heap is empty
//      else checks if length is 1
//      and returns value at that element
//      and decremements the length.
//      If length is not one, value at 
//      the index is set to value at element-1
//      Length is decremented, and properties
//      of heap are restored using heapify_down
template<class E>
E Heap<E>::extract()
{
    if (is_empty())
    {
        throw EmptyHeap(); 
    }

    else 
    {   
        if (length == 1)
        {
            E value = heap[0]; 
            length--; 
            return value; 
        }

        E value = heap[0]; 
        heap[0] = heap[length-1];  
        length--;
        heapify_down(0); 
        return value; 
    }
}

//Function name: get_parent_index, const
//Accepts: int
//Returns: int
//Does: Returns index of parent
//      If index is 0, returns 0
template<class E>
int Heap<E>::get_parent_index(int index) const
{
    if (index == 0)
    {
        return 0; 
    }

    else
    {
        return ((index-1)/2);
    }
}

//Function name: get_children_indeces
//Accepts: int, int by reference, int by reference 
//Returns: void 
//Does: Returns indeces of left and right children 
template<class E>
void Heap<E>::get_children_indices(int index, 
    int &left_child, int &right_child) const
{
    left_child = ((2*index) + 1);
    right_child = ((2*index)+ 2);
}

//Function name: get_value_at 
//Accepts: int
//Returns: type E 
//Does: Used for testing purposes
//      Throws out of bounds exception if index is
//      Less than 0 or index is greater than length
//      Otherwise returns value at an index in the heap
template<class E>
E Heap<E>::get_value_at(int index)
{
    if ((index < 0) || (index > length))
    {
        throw OutOfBounds(); 
    }

    else 
    {
        return heap[index]; 
    }
}

template class Heap<Patient>;
template class Heap<int>; 
