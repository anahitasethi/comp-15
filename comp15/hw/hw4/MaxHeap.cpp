/**************************
 * Anahita Sethi
 * COMP 15
 * Homework 4
 * MaxHeap Implementation
 **************************/ 

#include "MaxHeap.h"
#include <iostream> 
using namespace std; 

//Default Constructor 
template<class E>
MaxHeap<E>::MaxHeap()
{
}


//Function name: Heapify_up
//Parameters: int
//Returns: void
//Does: Swaps index with parent if it
//      is larger than its parent 
template<class E>
void MaxHeap<E>::heapify_up(int index)
{ 
    //Makes function call to get parent index 
    int parent_index = Heap<E>::get_parent_index(index); 
    //Value at index swaps with value at parent index
    //if it is larger than the value at the parent index
    if (Heap<E>::heap[index] > Heap<E>::heap[parent_index])
    {
        E temp = Heap<E>::heap[parent_index]; 
        Heap<E>::heap[parent_index] = Heap<E>::heap[index]; 
        Heap<E>::heap[index] = temp; 
        heapify_up(parent_index); 
    }
}

//Function name: heapify_down
//Parameters: int
//Returns: void
//Does: Compares left and right children
//      and swaps to restore properties
//      of a MaxHeap 
template<class E>
void MaxHeap<E>::heapify_down(int index)
{
    int left_child = 0; 
    int right_child = 0; 
    int largest = 0; 

    //Calls function from Heap to get children indeces 
    Heap<E>::get_children_indices(index, left_child, right_child); 

    //Checks if the left and right child are within bounds of array
    if (left_child < Heap<E>::length && right_child < Heap<E>::length)
    {
        //Sets largest to left child if it is larger than the right
        if (Heap<E>::heap[left_child] > Heap<E>::heap[right_child]) 
        { 
            largest = left_child; 
        }

        //Sets largest to right child if it is larger than the left 
        else if (Heap<E>::heap[right_child] > Heap<E>::heap[left_child])
        {
            largest = right_child; 
        }

        //If right and left children are equal, largest is set to 
        //left child 
        else if (Heap<E>::heap[right_child] == Heap<E>::heap[left_child])
        {
            largest = left_child; 
        }

        //Swaps value of largest child with value of index if largest
        //is greater than the index
        //Recursive call to heapify down is made to restore properties
        //of a MaxHeap
        if (Heap<E>::heap[largest] > Heap<E>::heap[index])
        {
            E temp = Heap<E>::heap[largest]; 
            Heap<E>::heap[largest] = Heap<E>::heap[index];
            Heap<E>::heap[index] = temp; 
            heapify_down(largest); 
        }
    }

    //Check to see if a left child exists but not a right child 
    else if (left_child < Heap<E>::length && right_child >= Heap<E>::length)
    {
        //Swaps value of left child with value of index if largest
        //is greater than the index
        //Recursive call to heapify down is made to restore properties
        //of a MaxHeap
        if (Heap<E>::heap[left_child] > Heap<E>::heap[index])
        {
            E temp = Heap<E>::heap[left_child]; 
            Heap<E>::heap[left_child] = Heap<E>::heap[index];
            Heap<E>::heap[index] = temp; 
            heapify_down(left_child); 
        }
    }
}

//Declares what types of variables can be passed in in the template class
template class MaxHeap<Patient>;
template class MaxHeap<int>; 