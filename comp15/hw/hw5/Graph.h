/*****************************
 * Anahita Sethi 
 * Graph.h
 * 
 * Interface for Graph class
 *
 * COMP15
 * Spring 2018
 * Lab 6 & Homework 5
 *
 * Jump back.
 ****************************/ 

#include "Queue.h"
#include "Stack.h"
#include "Actor.h"
#include <string> 
#include <iostream>
#include <ostream>
using namespace std; 

#ifndef GRAPH_H_
#define GRAPH_H_

class FullGraph : public exception {
public:
  const char *what() const throw() { return "My graph is full";}
};

class EmptyGraph : public exception {
public:
  const char *what() const throw() { return "My graph is empty";}
};

const string NULL_EDGE = "";
const int NULL_PRED = -1;

// wrapper functions
template<class Vertex>
int index_is(Vertex *vertices, Vertex v);

template<class Vertex>
class Graph
{
public:
    //Default constructor 
    Graph();

    //Parameterized constructor
    Graph(int);

    //Destructor 
    ~Graph(); 

    //Copy constructor
    Graph(const Graph &); 

    //Assignment operator
    Graph & operator = (const Graph &); 
 
    // Mutator functions
    void initialize_graph(int);
    void add_vertex(Vertex);
    void add_edge(Vertex, Vertex, string);

    // Accessor functions
    void print_matrix(ostream &) const;
    string get_edge(Vertex, Vertex) const;
    Vertex get_vertex(int) const; 

    // Helpers for BFS, DFS
    void get_to_vertices(Vertex, Queue<Vertex> &) const;
    void clear_marks();
    void mark_vertex(Vertex);
    bool is_marked(Vertex) const;
    bool is_vertex(Vertex) const;
    void initialize_path();
    void update_predecessor(Vertex, Vertex);
    void report_path(ostream &, Vertex, Vertex) const;

private:
    int curr_vertex;
    int num_vertices;
    Vertex *vertices;
    string **edges;
    int *path;
    bool *marks;
};

#endif


