/*
 * Queue.cpp
 *
 * Implementation for Queue class
 * (template class)
 *
 * COMP15
 * Spring 2018
 *
 */

#include <cstddef>
#include <new>
#include "Queue.h"
#include "Actor.h"

// Default constructor
template<class E>
Queue<E>::Queue()
{
    front = NULL;
    rear = NULL;
}

// Destrcutor
template<class E>
Queue<E>::~Queue()
{
    make_empty();
}

// Copy constructor
template<class E>
Queue<E>::Queue(const Queue<E> &q)
{
    if (q.front == NULL)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        try
        {
            front = new NodeType<E>;
            front->info = q.front->info;
            NodeType<E> *curr = front;
            NodeType<E> *orig = q.front;
            while (orig->next != NULL)
            {
                curr->next = new NodeType<E>;
                curr->next->info = orig->next->info;
                orig = orig->next;
                curr = curr->next;
                rear = curr;
            }
        }
        catch (bad_alloc exception)
        {
            cerr << "Could not copy queue!\n";
        }
    }
}

// Assignment operator
template<class E>
Queue<E> & Queue<E>::operator = (const Queue<E> &q)
{
    while (front != NULL)
    {
        NodeType<E> *temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
    if (q.front == NULL)
    {
        front = NULL;
    }
    else
    {
        try
        {
            front = new NodeType<E>;
            front->info = q.front->info;
            NodeType<E> *curr = front;
            NodeType<E> *orig = q.front;
            while (orig->next != NULL)
            {
                curr->next = new NodeType<E>;
                curr->next->info = orig->next->info;
                orig = orig->next;
                curr = curr->next;
                rear = curr;
            }
        }
        catch (bad_alloc exception)
        {
            cerr << "Could not copy queue!\n";
        }
    }
    return *this;
}

// Function make_empty
// Parameters: none
// Returns: none
// Does: empties out the queue and deallocates
template<class E>
void Queue<E>::make_empty()
{
    NodeType<E> *temp;

    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
 }


// Function is_full
// Returns: bool
// Does: tries to allocate a new node,
//       returns false if possible, true otherwise
template<class E>
bool Queue<E>::is_full() const
{
    NodeType<E> *location;
    try 
    {
        location = new NodeType<E>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

// Function is_empty
// Parameters: none
// Returns: true
// Does: checks if front pointer is NULL, returns true
//       if so, false otherwise
template<class E>
bool Queue<E>::is_empty() const
{
    return (front == NULL);
}

// Function enqueue
// Parameters: item to insert in the queue
// Returns: void
// Does: Puts new item on back of queue
template<class E>
void Queue<E>::enqueue(E new_item)
{
    if (is_full())
        throw FullQueue();
    else
    {
        NodeType<E> *new_node;
        new_node = new NodeType<E>;
        new_node->info = new_item;
        new_node->next = NULL;
        if (rear == NULL)
            front = new_node;
        else
            rear->next = new_node;
        rear = new_node;
    }
}

// Function dequeue
// Parameters: Item by reference
// Returns: void
// Does: Dequeues item off the front of the queue
//       and assigns to given item reference
template<class E>
void Queue<E>::dequeue(E &item)
{
    if (is_empty())
        throw EmptyQueue();
    else
    {
        NodeType<E> *temp;
        temp = front;
        item = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
}

// Template class definitions
template class Queue<int>;
template class Queue<char>;
template class Queue<string>;
template class Queue<Actor>;
