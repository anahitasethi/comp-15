/**********************
* Anahita Sethi
* COMP 15
* Homework 4
* MinHeap Header File
***********************/ 

#include "MinHeap.h"
#include <iostream> 
using namespace std; 

//Default Constructor 
template<class E>
MinHeap<E>::MinHeap()
{
}

//Function name: heapify_up
//Parameters: int
//Returns: void
//Does: Swaps index with parent if it
//      is smaller than its parent 
template<class E>
void MinHeap<E>::heapify_up(int index)
{ 
    //Call function to get parent index 
    int parent_index = Heap<E>::get_parent_index(index); 

    //If index is smaller than parent index, thus violating
    //Rules of a MinHeap, swap the values at those indeces 
    if (Heap<E>::heap[index] < Heap<E>::heap[parent_index])
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
//      of a MinHeap 
template<class E>
void MinHeap<E>::heapify_down(int index)
{
    int left_child = 0; 
    int right_child = 0; 
    int smallest = 0; 

    //Calls function from Heap to get children indeces 
    Heap<E>::get_children_indices(index, left_child, right_child); 

    //Check if left and right children are within bounds of array 
    if (left_child < Heap<E>::length && right_child < Heap<E>::length) 
    {
        //Sets smallest to left child if it is smaller than the right
        if (Heap<E>::heap[left_child] < Heap<E>::heap[right_child])
        { 
            smallest = left_child; 
        }

        //Sets smallest to right child if it is smaller than the left 
        else if (Heap<E>::heap[right_child] < Heap<E>::heap[left_child]) 
        {
            smallest = right_child; 
        }

        //If left and right child are equal, smallest is set to left 
        else if (Heap<E>::heap[right_child] == Heap<E>::heap[left_child]) 
        {
            smallest = left_child; 
        } 

        //Swaps smallest value with value at index 
        //Makes recursive call to heapify down again to restore
        //properties of MinHeap on the new subtree 
        if (Heap<E>::heap[smallest] < Heap<E>::heap[index])
        {
            E temp = Heap<E>::heap[smallest]; 
            Heap<E>::heap[smallest] = Heap<E>::heap[index];
            Heap<E>::heap[index] = temp; 
            heapify_down(smallest); 
        }
    }

    //Checks if left child is within bounds of array and right child is 
    //not. In this case, there is no right child but there is a left 
    //Swaps if value at left child is smaller than value at index 
    else if (left_child < Heap<E>::length && right_child >= Heap<E>::length)
    {
        if (Heap<E>::heap[left_child] < Heap<E>::heap[index])
        {
            E temp = Heap<E>::heap[left_child]; 
            Heap<E>::heap[left_child] = Heap<E>::heap[index];
            Heap<E>::heap[index] = temp; 
            heapify_down(left_child); 
        }
    }
}

//Declares what types of variables can be used in a template class
template class MinHeap<Patient>;
template class MinHeap<int>; 