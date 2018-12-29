/*****************************
 * Anahita Sethi
 * COMP 15
 * Homework 5
 * Six Degrees Implementation
 *****************************/ 

#include "SixDegrees.h"
#include <iostream>
#include <fstream> 
#include <ostream> 
#include <stdlib.h> 
#include <string> 
#include <sstream> 
using namespace std; 

//Global variable of number of actors 
const int NUM_ACTORS = 173; 

//Default constructor 
SixDegrees::SixDegrees()
{
    g.initialize_graph(NUM_ACTORS); 
}

//Function name: populate_graph
//Parameters: none
//Returns: void
//Does: Populates graph from file "actors.txt"
void SixDegrees::populate_graph()
{
    //Open file for reading 
    ifstream infile; 
    infile.open("actors.txt"); 

    //Checks if file is open 
    if (!infile.is_open()) 
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    int num_stars = 0; 
    while(!infile.eof() && num_stars <= NUM_ACTORS) 
    {
        //Try populating graph if graph is not full 
        try
        {
            string actor = ""; 

            //Gets actor name if it is not equal to delimiter 
            getline(infile, actor);  

            //New actor object with actors name
            //Calls parameterized constructor 
            Actor a(actor);
            string movie = ""; 

            //Enters loop if actor is not a blank space and movie 
            //is not equal to delimiter 
            while (actor != "" && movie != "*")
            { 
                //Get movie name
                //Inserts movie into LinkedList of 
                //movies of that actor object
                //if not equal to delimiter * 
                getline(infile, movie);  
                if (movie != "*")
                {
                    a.insert_movie(movie);  
                }

                //If movie is equal to delimiter, break 
                else
                {
                    break;  
                }
            }

            //If actor is not equal to an empty string
            //Add actor as a vertex
            //Call connect movies function
            //Increment counter variable 
            if (actor != "")
            {
                g.add_vertex(a);
                connect_movies(a, num_stars); 
                num_stars++; 
            }

            else
            {
                break; 
            }
        }

        catch (FullGraph exception)
        {
            cerr << exception.what() << endl;
            exit(1);
        }
    }

    //Close file 
    infile.close();
}

//Function name: connect_movies
//Parameters: Actor object, int number of actors
//Returns: void
//Does: Adds edge of type string of common movie 
void SixDegrees::connect_movies(Actor a1, int numstars)
{
    string connection = ""; 
    //Iterates through number of actors 
    for (int i = 0; i < numstars; i++)
    {
        //Calls connect fxn on vertex at index and actor
        //being passed in 
        connection = a1.connect(g.get_vertex(i)); 

        //Gets edge of the actors 
        g.get_edge(a1, g.get_vertex(i)); 

        //Adds edge in both directions if connect fxn does
        //not return an empty string 
        if (connection != "")
        { 
            g.add_edge(a1, g.get_vertex(i), connection); 
            g.add_edge(g.get_vertex(i), a1, connection); 
        }
    }  
}

//Function name: run 
//Parameters: istream and ostream object by reference
//Returns: void
//Does: Called from driver, prompts for names of two actors
//      Calls BFS function 
void SixDegrees::run(istream &in, ostream &out)
{
    //Populates graph with vertices and edges 
    populate_graph(); 

    out << "Enter two actor names separated by a new line." << endl
            << "Press ctrl-D to quit" << endl; 

    while (!in.eof())
    {
        //Continually prompts for actor names 
        string actor1, actor2; 
        getline(in, actor1); 

        if (in.eof())
        {
            exit(0); 
        }
    
        while (!g.is_vertex(actor1))
        {
            out << "Sorry, " << actor1 << " is not in the list\n"; 
            out << endl; 
            getline(in, actor1); 
        }

        getline(in, actor2); 
        while (!g.is_vertex(actor2))
        {
            out << "Sorry, " << actor2 << " is not in the list\n"; 
            out << endl; 
            getline(in, actor2); 
        }

        //Call to BFS using two actors 
        BFS(actor1, actor2, out);  
    }
}

//Function name: BFS
//Parameters: Actor object, actor object, 
//            reference to ostream object
//Returns: void
//Does: Uses Breadth-First Search to print a path and costar
//      distance from a to b
void SixDegrees::BFS(Actor start, Actor end, ostream &out)
{
    //BFS helper functions 
    g.clear_marks();
    g.initialize_path();

    //Create two queues
    Queue<Actor> q1; 
    Queue<Actor> q2; 

    //Create two actor objects 
    Actor current_vertex; 
    Actor neighbor;

    bool found = false; 
    
    //Enqueue start 
    q1.enqueue(start); 
    while(!q1.is_empty() && found == false)
    {
        q1.dequeue(current_vertex); 
        if (current_vertex == end)
        {
            found = true; 
            g.mark_vertex(current_vertex);
            break; 
        }

        else
        {
            g.get_to_vertices(current_vertex, q2); 
            g.mark_vertex(current_vertex); 

            while (!q2.is_empty())
            {
                q2.dequeue(neighbor); 
                if (!g.is_marked(neighbor))
                {
                    g.update_predecessor(current_vertex, neighbor); 
                }

                if (neighbor == end)
                {
                    found = true; 
                    break; 
                }

                else
                {
                    if (!g.is_marked(neighbor))
                    {
                        q1.enqueue(neighbor); 
                    }
                }
            }
        }

        //Print path from start to end 
        g.report_path(out, start, end); 
    }

    //Print no connection if no path found 
    if (found == false)
    {
        out << start << " and " << end << ": No connection" << endl; 
        out << endl; 
    }
        
}