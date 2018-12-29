/**********************************
 * Anahita Sethi 
 * Patient.cpp
 *
 * Implementation for Patient class
 * 
 * COMP15
 * Spring 2018
 * Homework 4 
 ********************************/ 

#include <iostream>
#include "Patient.h"
using namespace std;

// Default constructor
Patient::Patient()
{
    fname = "Jane";
    lname = "Doe";
    chest_pain = false;
    head_wound = false;
    temp = 98.6;
    pulse = 0;
    priority = FIVE;
    time_in = 0; 
    is_max = false; 
}

//Function name: get_priority, const
//Parameters: none
//Returns: Priority object 
//Does: gives access to private variable
//      priority
Priority Patient:: get_priority() const
{
    return priority; 
}

//Function name: get_time, const
//Parameters: none
//Returns: int
//Does: gives access to private variable
//      time_in, which is used in comparison
//      operators 
int Patient::get_time() const
{
    return time_in; 
}

// Parameterized constructor
Patient::Patient(string f, string l)
{
    fname = f;
    lname = l;
}

//Overloading < comparison operator
//Returns true if priority 1 is less than priority 2
//If priorities are equal, checks if first patient
//Came in before second patient 
bool operator < (const Patient &p1, const Patient &p2)
{
    if (p1.get_priority() < p2.get_priority()) 
    {
        return true;
    }
    else if (p1.get_priority() == p2.get_priority())
    {
      if (p1.get_time() < p2.get_time())
      {
         return true; 
      }

      else
      {
        return false; 
      }    
    }
    else
    {
      return false; 
    }    
}

//Overloading > comparison operator
//Returns true if priority 1 is greater than priority 2
//If priorities are equal, checks if first patient
//Came in before second patient
bool operator > (const Patient &p1, const Patient &p2)
{
    if (p1.get_priority() > p2.get_priority())
    {
      return true;
    }
    else if(p1.get_priority() == p2.get_priority()) 
    {
      if (p1.get_time() < p2.get_time())
      {
         return true; 
      }
      else
      {
        return false; 
      }      
    }
    else
    {
      return false; 
    }
}

//Overloading == comparison operator
//Returns true if priority 1 is equal to priority 2
//Else checks if first patient came in before second patient
bool operator == (const Patient &p1, const Patient &p2)
{
    if (p1.get_time() == p2.get_time())
    {
        return true; 
    }
    else
    {
        if (p1.get_time() < p2.get_time())
        {
            return true; 
        }
        else 
        {
            return false; 
        }
    }
}

// Print the patient
ostream & operator << (ostream &out, const Patient &p)
{
    out << p.fname << " " << p.lname << endl;
    out << ((p.head_wound) ? "Head wound\n" : "");
    out << ((p.chest_pain) ? "Chest pain\n" : "");
    out << "Pulse: " << p.pulse << endl;
    out << "Temp: " << p.temp << endl;
    out << "PRIORITY " << p.priority << endl;
    return out;
}

//Function name: calculate_priority 
//Returns: void
//Accepts: chest pain (bool), head wound (bool), 
//         temp (double), pulse (unsigned),
//         arrival time (int), priorities (bool)  
//Does: assigns priority based on vitals of patients 
void Patient::calculate_priority(bool c_pain, bool h_wound, double t, 
                                  unsigned p, int arrival, bool m)
{
  if ((h_wound == true && c_pain == true) || (h_wound == true && p < 90) 
     || (c_pain == true && p < 90))
  {
    // If highest = largest 
    // This will use a MaxHeap 
    // Dorchester Hospital 
    if (m == true)
    {
      priority = FIVE; 
    }

    // If highest = smallest 
    // This will use a MinHeap
    // MGH
    else
    {
      priority = ONE; 
    }
  }

  else if ((h_wound == true && p >= 90) || (c_pain == true && p >= 90)) 
  {
     if (m == true)
      {
        priority = FOUR; 
      }

      else
      {
        priority = TWO; 
      }
  }

  else if (p < 90 && t > 100 && h_wound == false && c_pain == false) 
  {
      priority = THREE; 
  }

  else if ((t > 100 && h_wound == false && c_pain == false) || 
          (p < 90 && h_wound == false && c_pain == false)) 
  {
      if (m == true)
      {
        priority = TWO; 
      }

      else
      {
        priority = FOUR; 
      }
  }

  else
  { 
      if (m == true)
      {
        priority = ONE; 
      }

      else
      {
        priority = FIVE; 
      }
  } 

  chest_pain = c_pain; 
  head_wound = h_wound; 
  temp = t; 
  pulse = p; 
  time_in = arrival; 
  is_max = m; 
}

