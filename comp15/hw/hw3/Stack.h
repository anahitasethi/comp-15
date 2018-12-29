/*************************
 * Anahita Sethi
 * COMP 15
 * HW 3
 * Stack Header File
 ************************/

#include <exception> 
#include <string> 

#ifndef STACK_H_
#define STACK_H_

const int MAX_SIZE = 50; 

//Class exception of having a full stack
class FullStack : public std::exception{
public: 
    const char* what() const throw() {
        return "Oh no, the stack is full!\n";
    }
};

//Class exception of having an empty stack
class EmptyStack : public std::exception{
public:
    const char * what() const throw() {
        return "Sad, the stack is empty!\n"; 
    }
}; 

class Stack
{
public:
    //Default constructor
    Stack(); 

    //Checks if stack is empty
    bool is_empty() const; 

    //Returns true if stack is full 
    //Tries to allocate memory if space
    //is available
    bool is_full() const; 

    //Empties out stack 
    void make_empty(); 

    //Returns number of elements on stack
    int get_size() const; 

    //Returns value of element at top of stack
    double top() const; 

    //Pushes given paramater on top of stack 
    void push (double);

    //Removes element on top of stack 
    void pop(); 

private: 
    int head;   
    //Declares a static array 
    double stack [MAX_SIZE]; 
    int capacity; 
}; 



#endif 
