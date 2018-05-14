#ifndef GDC_H
#define GDC_H
#include<iostream>
using namespace std;

//vertex/edge
struct node
{
  int id; //node ID
  bool edgeCheck; //if "node" is an edge
  int weight; //edge weight value
};

class gdc
{
 public:
  gdc();
  ~gdc();
  int addVert(int id); //creates a vertex with some label
  int addEdge(int id1, int id2, int weight); //adds an edge between two vertices with a certain weight
  int removeVert(int id); //removes a vertex and all its connections
  int removeEdge(int id1, int id2); //removes an edge
  int findPath(int id1, int id2); //finds the shortest distance between two vertices
  int display(); //displays chart

 private:
  int addVert(node* &head, int id); //with an id, make the vertex
  int addEdge(node* &first, node* &second, int weight); //with nodes selected, makes an edge with weight
  int removeVert(node* &head); //removes vertex
  int removeEdge(node* &first, node* &second); //removes edge
  int findPath(node* &first, node* &second); //find distance/if there is a path
  int display(node* head); //display function
  node* head;
};

#endif
	       
