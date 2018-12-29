/*
 * Stack.h
 * COMP15
 * Spring 2018
 *
 * Interface for stack class
 */

#include <exception>
#include "NodeType.h"
using namespace std;


#ifndef STACK_H_
#define STACK_H_

class FullStack : public exception {
public:
    const char *what() const throw() { return "Full Stack OVERFLOOOOW";}
    };

class EmptyStack : public exception {
public:
    const char *what() const throw() { return "NO CAN HAZ STACK IS FULL"; } 
};

template<class E> class Stack
{
public:
    Stack();

    // The Rule of Three!
    ~Stack();
    Stack(const Stack &);
    Stack & operator = (const Stack &);

    // Stack operations
    void push(E);
    void pop();
    E top() const;
    int get_size() const;

    bool is_full() const;
    bool is_empty() const;

    void make_empty();

private:
    NodeType<E> *top_ptr;
    int size;
};



#endif
