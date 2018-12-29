/***********************
 * Anahita Sethi
 * COMP 15
 * HW3
 * RPN Implementation
 **********************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "RPNCalc.h"
using namespace std;  

//Default constructor 
RPNCalc::RPNCalc()
{
  quit = false; 
}

//Name:run
//Parameters:none
//Returns:void
//Does: called from main, calls run_from function
//      using standard input cin 
void RPNCalc::run()
{
  run_from(cin);
}

//Name:run_from
//Parameters: reference to an istream object
//Returns:void
//Does: Handles user inputs and performs operations
//      using RPN calculator notation 
void RPNCalc::run_from(istream &in)
{ 
  //Declares and initializes variables 
  string input = ""; 
  double num = 0;  
  //Takes in user input and stores it in a string 
  in >> input; 

  //Enters loop as long as user does not input quit or file has 
  //reached the end 
  while ((quit == false) && (!in.eof()))
  {  
    //Calls check for double function
    //Tries to push number onto stack if function returns true
    if (check_for_double(input, num) == true)
    {
      try
      {
        s.push(num);    
      }
      //Catches exception if stack is full 
      catch(FullStack exception)
      {
        cerr << exception.what() << endl; 
      }
    }

    //Calls function to check if input is an operator
    //If function returns true, tries to store top values
    //And pop values off the stack 
    else if (is_operator(input) == true)
    {
      double first, second; 

      try
      {
        first = s.top(); 
        s.pop(); 
        second = s.top();
        s.pop();  
      }
      
      //Catches exception if stack is empty 
      catch(EmptyStack exception)
      {
        cerr <<exception.what() << endl; 
      }

      //Handles all operations using inputed doubles
      //Pushes the result onto the stack 
      if (input == "-")
      {
        s.push(second - first); 
      }

      else if (input == "+")
      {
        s.push(second + first); 
      }

      else if (input == "*")
      {
        s.push(second * first); 
      }

      else if (input == "/")
      {
        s.push(second / first); 
      }
    }

    //Prints top value if user inputs "P" or "p"
    else if ((input == "P") || (input == "p"))
    {
      if (!s.is_empty())
      {
        cout << s.top() << endl; 
      }

      else
      {
        return; 
      }
    }

    //Empties out stack if user inputs "C" or "c"
    else if ((input == "C") || (input == "c"))
    {
      s.make_empty(); 
    }

    //Exits out of program if user inputs "Q" or "q"
    else if ((input == "Q") || (input == "q"))
    {
      exit(0);
    } 

    //Accepts another filename input if user inputs "F" or "f"
    else if ((input == "F") || (input == "f"))
    {
      string filename; 
      in >> filename; 
      ifstream infile; 

      //Open file and checks for errors 
      infile.open(filename); 
      if (!infile.is_open())
      {
        cerr << "Could not open file\n"; 
      }
  
      //Calls run function using text and numbers in file  
      run_from(infile); 
      
      //Closes file 
      infile.close(); 
    }
    
    //Checks for valid inputs 
    else 
    {
      cout << "Command is not implemented" << endl; 
    }

    in >> input; 
  } 

  return; 
}

//Name: is_operator
//Parameters: string by reference
//Returns: bool
//Does: Checks if user input is an operator
bool RPNCalc::is_operator(const string& input)
{
  string operations[] = {"-", "+", "*", "/"}; 
  for (int i = 0; i < 4; i++)
  {
    if (input == operations[i])
    {
      return true; 
    }
  }
  return false; 
}

//Name: check_for_double
//Parameters: string, double by reference
//Returns: bool 
//Does: Checks if user input is a double
//Changes inputed string to a double and returns true
//If not a double, return false 
bool RPNCalc::check_for_double(const string input, double &num)
{
  try 
  {
    num = stod(input);
    return true; 
  }
  catch (invalid_argument exception)
  {
    return false; 
  }
}
