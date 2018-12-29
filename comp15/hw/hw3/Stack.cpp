/*********************
 * Anahita Sethi
 * COMP 15
 * HW 3
 * Stack Class
 *********************/

#include "Stack.h"
#include <cstddef>
#include <new>
#include <iostream>
using namespace std; 


//Default constructor 
Stack::Stack()
{
    //Head will always be one less than length
    //Initializes head to -1 
    head = -1; 

    //For loop to iterate through stack and 
    //initialize each element  
    for (int i = 0; i < MAX_SIZE; i++)
    {
        stack[i] = 0; 
    }

    //Capacity is set to constant max size
    //Which is 50 
    capacity = MAX_SIZE; 
}

//Name:is_empty
//Parameters: none
//Returns:bool
//Does:Checks if stack is empty
bool Stack::is_empty() const 
{ 
    if ((head+1) == 0)
    {
        return true; 
    }

    else
    {
        return false; 
    }
}

//Name:is_full
//Parameters: none
//Returns: bool 
//Does: Checks if stack is full
//          Compares head to capacity 
bool Stack::is_full() const
{
    if ((head+1) == capacity)
    {
        return true;  
    }

    else
    {
        return false; 
    }
}

//Name:make_empty
//Paramters: none
//Returns: void
//Does: Sets head to -1
//which empties out stack 
void Stack::make_empty()
{
    head = -1; 
}

//Name:get_size
//Parameters: none
//Returns: int
//Does: returns size of stack 
int Stack::get_size() const 
{
    return (head + 1); 
}

//Name:top
//Paramaters: none
//Returns: double
//Does: checks if stack is empty
//          Returns top element, which
//          was inserted last 
double Stack::top() const
{
    if (!is_empty())
    {
        return stack[head]; 
    }
    return 0.0; 
}

//Name:push
//Paramaters: double
//Returns: void
//Does: throws an exception
//          if stack is full;
//          pushes top number onto stack
//          and increments head if
//          stack is not full 
void Stack::push(double num)
{
    if (is_full())
    {
        throw FullStack(); 
    }
    
    stack[head+1] = num; 
    head++; 
}

//Name:pop
//Parameters: none
//Returns: void 
//Does: throws an exception if 
//          stack is full; pops 
//          top number off stack by 
//          decrementing head 
void Stack::pop() 
{
    if (is_empty())
    {
        throw EmptyStack();  
    }
    head--; 
}
