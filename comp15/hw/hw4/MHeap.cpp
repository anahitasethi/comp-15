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

template<class E>
void MinHeap<E>::heapify_up(int index)
{
}


template<class E>
void MinHeap<E>::heapify_down(int index)
{
	//Check lengths 
	int left_child = 0; 
	int right_child = 0; 
	int largest = index; 
	Heap<E>::get_children_indices(index, left_child, right_child); 

	//Base case
	//If the MinHeap is ordered correctly and the index is smaller than 
	//the left and right children 
	if ((Heap<E>::heap[index] <= Heap<E>::heap[left_child]) && (Heap<E>::heap[index] <= Heap<E>::heap[right_child]))
	{
		return; 
	}

	//Swap left chid and index if left child is smaller 
	if (Heap<E>::heap[left_child] < Heap<E>::heap[index])
	{
		int temp = Heap<E>::heap[left_child]; 
		Heap<E>::heap[left_child] = Heap<E>::heap[index];
		Heap<E>::heap[index] = temp; 
		largest = left_child; 
		heapify_down(largest); 
	}

	//Swap right child and index if right child is smaller 
	if (Heap<E>::heap[right_child] < Heap<E>::heap[index])
	{
		int temp = Heap<E>::heap[right_child]; 
		Heap<E>::heap[right_child] = Heap<E>::heap[index];
		Heap<E>::heap[index] = temp; 
		largest = right_child; 
		heapify_down(largest); 
	}

	if (Heap<E>::heap[right_child] < Heap<E>::heap[index] &&  Heap<E>::heap[left_child] < Heap<E>::heap[index])
	{
		if (Heap<E>::heap[right_child] < Heap<E>::heap[left_child])
		{
			int temp = Heap<E>::heap[right_child]; 
			Heap<E>::heap[right_child] = Heap<E>::heap[left_child];
			Heap<E>::heap[left_child] = temp; 
			largest = left_child; 
			heapify_down(largest); 
		}

		else
		{
			int temp = Heap<E>::heap[left_child]; 
			Heap<E>::heap[left_child] = Heap<E>::heap[right_child];
			Heap<E>::heap[right_child] = temp; 
			largest = right_child; 
			heapify_down(largest); 
		}
	}

	return; 
}