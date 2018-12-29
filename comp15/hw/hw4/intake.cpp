/* 
 * intake.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Driver for HW4
 * 
 * Carney Hospital in Dorchester
 * vs. MGH downtown. 
 * Go Team Dorchester!
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Patient.h"
#include "MinHeap.h"
#include "MaxHeap.h"
using namespace std;

const string INFILE   = "patient_data.txt";
const string OUTFILE1 = "all_patients_max.txt";
const string OUTFILE2 = "all_patients_min.txt";
const string OUTFILE3 = "doctors_on_duty_max.txt";
const string OUTFILE4 = "doctors_on_duty_min.txt";

const int DOCTOR_EFFICIENCY = 5;

Patient read_one_patient(istream &, bool);
void read_in_patients(Heap<Patient> *, bool);
void all_patients_minmax(Heap<Patient>* , string);
void doctors_on_duty(Heap<Patient> *, string, bool);

int main()
{
	bool is_max = true;
	Heap<Patient> *Carney = new MaxHeap<Patient>;
	Heap<Patient> *MGH = new MinHeap<Patient>;

	read_in_patients(Carney,  is_max);
	read_in_patients(MGH, !is_max);
	
	all_patients_minmax(Carney, OUTFILE1);
	all_patients_minmax(MGH, OUTFILE2);

	doctors_on_duty(Carney, OUTFILE3,  is_max);
	doctors_on_duty(MGH, OUTFILE4, !is_max);

    delete Carney;
    delete MGH;

	return 0;
}

// Function read_in_patients
// Parameters: Heap (min or max), bool 
// Returns: void
// Read patient file and insert into Heap object
void read_in_patients(Heap<Patient> *heap, bool minmax)
{
	ifstream in;
	in.open(INFILE.c_str());

	if (!in.is_open()) 
	{
		cerr << "Error opening " << INFILE << endl;
		exit(1);
	}
	while(!in.eof()) 
	{
        try
        {
    		heap->insert_item(read_one_patient(in, minmax));
        }
        catch (FullHeap exception)
        {
            cerr << exception.what() << endl;
            exit(1);
        }
	}

	in.close();
}

// Function read_one_patient
// Parameters: istream reference, bool
// Returns: one patient object
// Does: Reads the next patient from the input file
Patient read_one_patient(istream &in, bool minmax)
{
	string fname, lname, input;
	bool head, chest;
	double temp;
	unsigned pulse, time_in;

    in >> fname >> lname;
    Patient p(fname, lname);
		
	getline(in, input);
	getline(in, input);
	(input == "Has head wound") ? head = true : head = false;
		
	getline(in, input);
    try
    {
    	temp = stod(input);
	}
    catch (invalid_argument exception)
    {
        cerr << "READ FAILURE: temp is not a double\n";
        exit(1);
    }
	getline(in, input);
    try
    {
    	pulse = stoi(input);
    }
    catch (invalid_argument exception)
    {
        cerr << "READ FAILURE: pulse is not an unsigned int\n";
        exit(1);
    }
	
	getline(in, input);
	(input == "Has chest pain") ? chest = true : chest = false;

	getline(in, input);
    try
    {
    	time_in = stoi(input);
    }
    catch (invalid_argument exception)
    {
        cerr << "READ FAILURE: time is not an int\n";
        exit(1);
    }
	getline(in, input);

	p.calculate_priority(chest, head, temp, pulse, time_in, minmax);
	return p;	
}

// Function all_patients_minmax
// Input: Heap (min or max) of patients, name of output file
// Returns: nothing
// Does: extracts every item out of the heap and prints to 
//       the given file.
void all_patients_minmax(Heap<Patient>* heap, string outfile)
{
	ofstream out;
	out.open(outfile.c_str());
	if (!out.is_open()) 
	{
		cerr << "Error opening " << outfile << endl;
        exit(1);
	}

	while (!heap->is_empty()) 
	{
		out << heap->extract() << endl;
	}
	out.close();
}

// Function: doctors on duty
// Input: Heap (min or max), filename, bool for what kind of heap
// Returns: nothing
// Does: Doctors help one in five patients. We read in from
//       an input file, insert Patients into a heap, and extract
//       who the doctor can help, and print the result
void doctors_on_duty(Heap<Patient> *heap, string outfile, bool minmax)
{
	ifstream in;
	ofstream out;

	in.open(INFILE.c_str());
	if (!in.is_open())
	{
		cerr << "Error opening " << INFILE << endl;
		exit(1);
	}

	// a doctor is able to help one in five patients as they enter
	for (int count = 0; !in.eof(); count++)
	{
        try
        {
    		heap->insert_item(read_one_patient(in, minmax));
        }
        catch (FullHeap exception)
        {
            cerr << exception.what();
            exit(1);
        }

		if ((count % DOCTOR_EFFICIENCY) == 1)
		{
			heap->extract();
		}
	}
	in.close();

	out.open(outfile.c_str());
	if (!out.is_open())
	{
		cerr << "Error opening " << outfile << endl;
		exit(1);
	}

	// print the patients who are still waiting
	while (!heap->is_empty())
	{
		out << heap->extract();
	}
	out.close();	
}


