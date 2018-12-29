/***************************************************
 * Anahita Sethi 
 * MinHeap.h
 *
 * COMP15
 * Spring 2018
 *
 * Derived class for MinHeap type
 * Inherits from abstract Heap class
 *
 * The memory heap is neither a Heap nor
 * in memory. Discuss.
 *
 * (Oh no, but jk you guys. It's  only half true. 
 * The memory heap is in memory but not a Heap like,
 * you know, a heap.)
 *
 *
 ***************************************************/ 

#include "Heap.h"

#ifndef MINHEAP_H_
#define MINHEAP_H_

template<class E> class MinHeap : public Heap<E>
{
public:
	//Default constructor 
    MinHeap();
    
private: 
    // Overriding purely virtual functions
    void heapify_up(int);
    void heapify_down(int);
};

#endif
