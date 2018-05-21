#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<string.h>
#include<climits>
using namespace std;

const int MAX = 20;

class graph
{
 public:
  graph();
  graph(int value);
  ~graph();
  int addV(const char* label);
  int remV(const char* label);
  int addE(const char* l1, const char* l2, int weight);
  int remE(const char* l1, const char* l2);
  int display();
  int findPath(const char* l1, const char* l2);
  
 private:
  int** array;
  char** verts;
  bool* copy;
  int size;
  int findIndex(const char* label);
  int shortE(bool visit[], int weight[]);
  void printPath(int weight[], int index);
};

#endif
