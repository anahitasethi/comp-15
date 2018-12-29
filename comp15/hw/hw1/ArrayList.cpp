/*******************************************
 * Anahita Sethi 
 * Array.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for Arrrrrrray of Pirates
 *******************************************/ 

#include "ArrayList.h"
#include <iostream> 
using namespace std; 

// Default constructor
// Length and current position default to 0
ArrayList::ArrayList()
{
    length = 0;
    curr_pos = 0;

    // Creates new variable equal to constant 100 
    curr_capacity = MAX_PIRATES; 
    // Dynamically allocates space on heap for Pirate array
    pirates = new Pirate[MAX_PIRATES];  
}

// Function find_pirate
// Inputs: Pirate object, bool by reference
// Returns: Pirate object
// Does: Looks for pirate in the array, modifies bool if found
//       Returns the object from the list and not the passed one
//       (In case they're different.)
Pirate ArrayList::find_pirate(Pirate p, bool &found) const
{ 
    int location = 0;

    while ((location < length) && !found)
    {
        if (p == pirates[location])
        {
            found = true;
            p = pirates[location];
            break;
        }
        location++;
    }
    return p;
}

// Function insert_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Looks for pirate by calling find_pirate
// Adds pirate to end of array
// Increases length
// Calls expand function if length greater than current capacity 
// Adds pirates to end of array after size expanded  
void ArrayList::insert_pirate(Pirate p)
{ 
    // Declares and initializes variable found
    // Found is a paramater of fxn find_pirate
    bool found = false; 

    //Calls find pirate function 
    find_pirate(p, found); 

    //Only inserts a pirate if pirate is not found
    //Do not want duplicates 
    if (found == false)
    {
        //Adds pirate if number of pirates is less than max pirates
        if (length < curr_capacity)
        {
    	     pirates[length] = p;
    	     length++; 
        }  

        //Calls expand function if number of pirates is greater than
        // or equal to max pirates   
        if (length >= curr_capacity)
        {	
	         expand();   
        }
    }    
}

 
// Function delete_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Looks for pirate
// Deletes pirate, shifts everything else over
// Calls shrink function if length less than half current capacity 
void ArrayList::delete_pirate(Pirate p)
{
  // Declares and initializes variables 
  int location = 0; 
  bool found = false; 

  //Iterates through pirate array 
  for (int i = 0; i < length; i++)
  { 
      if (pirates[i] == p)
      { 
          // Searches for pirate to delete
          // If found, update bool to true
          // Set location to that pirate index
          // Break out of conditional when found 
          found = true; 
          location = i; 
          break; 
      }  
  }

  // Deletes pirate only if it's found 
  if (found == true)
  {  
      // Iterates through array
      // Shifts pirates to the left
      for (int j = location; j < length - 1; j++)
	    { 
		    pirates[j] = pirates[j+1];
	    }
      
      length--; 
  }
	
  // Calls shrink function if number of pirates is
  // less than or equal to half of max pirates 
  if (length <= (curr_capacity/2))
	{
      shrink();
	}  
}


// Function get_next_pirate
// Input: None
// Returns: Pirate object
// Does: Returns pirate at curr_pos
//       Increments curr_pos, but wraps around
Pirate ArrayList::get_next_pirate()
{
  Pirate p = pirates[curr_pos];
  curr_pos = (curr_pos + 1) % length;
  return p;
}

// Function make_empty
// Input: none
// Returns: none
// Does: sets length to 0 (memory not modified)
void ArrayList::make_empty()
{
  length = 0;
}

// Function reset_array
// Input: none
// Returns: none
// Does: sets curr_pos to 0 
void ArrayList::reset_array()
{
  curr_pos = 0;
}

// Function print
// Input: Reference to ostream object outfile 
// Returns: none
// Does: Prints array from 0 to length to outfile 
// Accessor function, const 
// Prints comma to file if it's not the last pirate
void ArrayList::print(ostream& outfile) const 
{
    // Iterates through pirates
    // Prints pirate to file followed by comma
    for (int i = 0; i < length; i++)
    {
        if (i != (length-1))
        {
          pirates[i].print(outfile);
          outfile << ", "; 
        } 
        
        // If last pirate in the list, only prints
        // pirate and not a comma 
        if (i == (length - 1))
        {
          pirates[i].print(outfile);
        }
    } 
}

// Function get_length
// Input: none, oncst
// Returns: int
// Does: Returns the value in length attribute
int ArrayList::get_length() const
{
    return length;
}

//Function expand
//Input: none
//Returns: none
//Does: Expands the array to hold 200 pirates
void ArrayList::expand()
{ 
  // Doubles the current capacity 
  curr_capacity *= 2; 
  cout << "Expand to " << curr_capacity  << endl; 

  // Dynamically allocates space using updated capacity 
  Pirate *place = new Pirate[curr_capacity]; 

  //Copies data from old array to new using for loop 
  for (int i = 0; i < length; i++) 
  {
	   place[i] = pirates[i]; 
  } 

  // Deletes old array 
  delete []pirates; 

  //Points old pointer to new placeholder array 
  pirates = place; 
} 
	
//Input: none
//Returns: none
//Does: Shrinks array to half its size  
void ArrayList::shrink()
{ 
  // Shrinks current capacity in half 
  curr_capacity /= 2; 
  cout << "Contract to " << curr_capacity << endl; 

  // Dynamically allocates space using updated capacity 
  Pirate *temp = new Pirate[curr_capacity]; 

  //Copies data from old array to new using for loop 
  for (int i = 0; i < length; i++)
  {
	 temp[i] = pirates[i]; 
  }

  //Deletes old array 
  delete []pirates; 

  //Points old pointer to new placeholder array 
  pirates = temp; 
}

// Destructor
// Deletes dynamic pirates array
ArrayList::~ArrayList()
{
 delete []pirates;
} 
 
