/**********************
 * Anahita Sethi
 * COMP 15
 * Homework 4
 * MaxHeap Header File 
 **********************/ 

#include "Heap.h"

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

template<class E> class MaxHeap : public Heap<E>
{
public:
	//Default constructor 
    MaxHeap();
 

private: 
    // Overriding purely virtual functions
    void heapify_up(int);
    void heapify_down(int);
};

#endif
