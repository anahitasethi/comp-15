/*******************************************
 * Anahita Sethi 
 * LinkedList.cpp
 * COMP15
 * Spring 2018
 * 
 * Implementation for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A mars bar!
 *******************************************/

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l)
{
    length = l.length;
    curr_pos = NULL;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
          curr->next = new NodeType;
          curr->next->info = orig->next->info;
          curr->next->next = NULL;
          orig = orig->next;
          curr = curr->next;
        }
    }
    return *this;
}

// Function insert_planet
// Input: Planet object
// Returns: None
// Does: Adds Planet to beginning of array
//       Increases length 
void LinkedList::insert_planet(Planet p)
{
    NodeType *location = new NodeType;
    location->info = p;
    location->next = head;

    head = location;
    length++;
}

// Function get_next_planet
// Inputs: none
// Returns: none
// Does: Returns Planet object at current pos
// Wraps around to beginning if we're at the end
// Returns a default planet if empty
Planet LinkedList::get_next_planet()
{
    if (length == 0)
    {
        Planet p;
        return p;
    }
    if (curr_pos == NULL)
        curr_pos = head;
    else
        curr_pos = curr_pos->next;
    return curr_pos->info;
}

// Function get_length, const
// Inputs: none
// Returns: int, length of list
int LinkedList::get_length() const
{
    return length;
}

// Function find_planet
// Inputs: Planet object, bool reference 
// Returns: found Planet 
// Does: Searches for the first instance of a planet 
Planet LinkedList::find_planet(Planet p, bool &found) 
{
    // Creates new pointer
    NodeType *curr; 

    // Pointer points to beginning of list 
    curr = head; 

    //Loops as long as pointer doesnt point to null 
    while (curr != NULL)
    { 
        // Conditional for finding planet 
        // Updates bool value and returns object 
        if (curr -> info == p)
        { 
            found = true;  
            return p; 
        } 
        
	// Curr points to next planet if not found
        else 
        {
            curr = curr -> next; 
            found = false; 
        }
    } 
    found = false;  
    return p; 
}

//Function: reset_list
//Inputs: none
//Returns: void
//Does: points curr_pos to NULL 
void LinkedList::reset_list()
{
    curr_pos = NULL; 
}

//Function: is_full
//Inputs: none
//Returns: bool 
//Does: Accessor, const function
//      Tries to allocate a NodeType
//      If allocation fails, LinkedList
//      is full 
bool LinkedList::is_full() const 
{
  try 
  {
      NodeType *node = new NodeType; 
      delete node; 
      return false; 
  }

  catch(std::bad_alloc exception)
  {
      return true; 
  }
}

// Function delete_planet
// Inputs: Planet object
// Returns: void
// Does: Deletes planet if the list is not empty, 
// the planet object is found, and if planet
// is the desired one to be deleted 
void LinkedList::delete_planet(Planet p) 
{ 
    //Returns if list is empty                                                  
    if (get_length() == 0)
    {
        return;
    }

    // Returns if planet object is not found  
    bool found = false;
    find_planet(p, found);
    if (found == false)
    {
        return;
    }

    //Declare and point two pointers 
    //to beginning of list
    NodeType *node = head;
    NodeType *prev = head;

    // Deletes node and updates length 
    // if one item in list
    if (get_length() == 1)
    { 
        delete node;
        length--;
        return;
    }

    // Loops while next planet not pointing 
    // to null
    while (node -> next !=NULL)
    { 
        // Conditional for node that shouldn't
        // be deleted 
        if (node -> info != p)
        {
            prev = node; 
            node = node -> next; 
        }

	// Deletes node that matches planet object 
        if (node -> info == p)
        {  
            prev -> next = prev -> next -> next; 
            delete node; 
            length--; 
            return; 
        }
    }
}

// Function print, const
// Inputs: ostream object
// Returns: none
// Does: prints every element in the list
void LinkedList::print(ostream &out) const
{
    NodeType *location = head;
    while (location != NULL)
    {
        (location->info).print(out);
        out << endl;
        location = location->next;
    }
}


//Destructor 
//Deallocates all allocated memory in linked list 
LinkedList::~LinkedList() 
{
    //Points current to beginning of list
    NodeType *current = head;  

    //Creates new temporary pointer
    NodeType *temp; 

    // Loops while  current not pointing to null
    while (current != NULL)
    {
        temp = current -> next;   
        current = temp; 
    }
    head = NULL; 
} 


//Function: make_empty
//Inputs: none
//Returns: void
//Does: Deallocates allocated memory  
void LinkedList::make_empty()
{  
    // points temporary pointer to 
    // beginning of list                                    
    NodeType *temp = head;
    // points next pointer to next planet 
    // in list 
    NodeType *next_ptr =  head -> next; 

    //Iterates while temp doesnt point to NULL 
    while (temp != NULL)
    { 
      // Temp points to what next pointer 
      // points to 
      temp = next_ptr; 
	
      // Points next pointer to next planet
      // if next pointer doesnt point to NULL  
      if (next_ptr != NULL)
      {
          next_ptr = next_ptr -> next; 
      }
    }
    head = NULL; 
}                                                                 
                                                                                
//Copy Constructor
//Inputs: reference to a const LinkedList object
//Returns: nothing
//Does: Creates object by initializing it with
//      object of the same class 
LinkedList::LinkedList(const LinkedList &l) 
{ 
    //Allocates memory for new pointer to node 
    NodeType *node = new NodeType; 

    // Head points to what node points to 
    head = node; 

    // Creates copy if pointing to NULL 
    if (l.head == NULL)
    {
        head = NULL;
	    length = l.length; 
	    curr_pos = l.curr_pos; 
	    return; 
    }

    else
    {
  	    head -> info = l.head -> info;  
  	    head -> next = NULL; 
	
	    //Populate planet after allocating
	    //another NodeType
  	    NodeType *orig = l.head; 
  	    NodeType *curr = head;

	    //Makes a deep copy of every element 
	    while (orig -> next != NULL)
  	    {
    	    curr -> next = new NodeType; 
            curr->next->info = orig->next->info; 
    	    curr -> next -> next = NULL; 
    	    orig = orig -> next; 
    	    curr = curr -> next; 
  	        length = l.length;
	        curr_pos = l.curr_pos;  
	    } 
    
        //Update length and current position
        length = l.length; 
        curr_pos = l.curr_pos; 
    }
}
