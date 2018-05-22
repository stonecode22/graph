#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<string.h>
#include<climits>
using namespace std;

//Sets up the MAX limit of vertices
const int MAX = 20;

class graph
{
 public:
  graph(); //creates a bool table
  graph(int value); //creates the vertex & array (graph) 
  ~graph(); //deconstructor
  int addV(const char* label); //Adds a vertex given a name
  int remV(const char* label); //Deletes vertex based on name
  int addE(const char* l1, const char* l2, int weight); //Adds edge dependent on two existing vertices
  int remE(const char* l1, const char* l2); //Deletes edge dependent on two existing vertices
  int display(); //displays graph (excluding bool table)
  int findPath(const char* l1, const char* l2); //finds shortest path of a beginning vertex to an end vertex
  
 private:
  int** array; //graph displaying the edges
  char** verts; //displays vertices
  bool* copy; //truth table that decides whether or not to show a vertex axis (works together with deletion)
  int size; //size of the arrays (the MAX, 20)
  int findIndex(const char* label); //finds the index of a vertex
  int shortE(bool visit[], int weight[]); //shortEdge
  void printPath(int weight[], int index); //Print the shortest path (Index path & Weight value)
};

#endif
