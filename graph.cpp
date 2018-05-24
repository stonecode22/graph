#include"graph.h"

//constructor to initalize bool table
graph::graph()
{
  size = MAX; //make size MAX (20)
  copy = new bool[size]; //make a bool chart
  for(int i = 0; i < size; i++) //initialize the elements to false
    {
      copy[i] = false;
    }
}

//constructor to initalize edge and vertex tables
graph::graph(int value)
{
  size = value; //value is size, which is MAX
  copy = new bool[size]; //bool table
  for(int i = 0; i < size; i++)
    {
      copy[i] = false;
    }
  array = new int*[size]; //edge table c
  for(int i = 0; i < size; i++)
    {
      array[i] = new int[size]; //make space for a 2d array
      for(int k = 0; k < size; k++)
	{
	  array[i][k] = 0; //initialize index values to 0
	}
    }
  verts = new char*[size]; //make a vertex table inserting into the array table (creating a 2 dim. array)
}

//deconstructor to delete everything
graph::~graph()
{
  for(int i = 0; i < size; i++)
    {
      delete[] array[i]; //delete each index in the array
    }
  delete[] array; //delete the entire array itself
  for(int i = 0; i < size; i++)
    {
      if(copy[i] == true) //if not already deleted (use of bool table)
	{
	  delete[] verts[i]; //then delete the index
	}
    }
  delete[] verts; //delete the entire verts table
  delete[] copy; //delete the bool table after
  size = 0; //make size = 0;
}

//Add Vertex
int graph::addV(const char* label)
{
  int index = findIndex(label); //find the index for the label
  if(index == -1) //if it returns -1 (-1 means "empty/space allocated")
    {
      return 0; //do nothing
    }
  if(index < size) //if the index is less than the size
    {
      verts[index] = new char[strlen(label)+1]; //make a new vertex in the next empty spot
      strcpy(verts[index], label); //copy label into the vertex[index]
      copy[index] = true; //make the bool value true to indicate that it is an active, existing vertex
      return 1;
    }
  else //if size is smaller (does not fit in array)
    {
      return 0; //do nothing
    }
}

//Display the vertices and edge values between them
int graph::display()
{
  cout << " ";
  for(int i = 0 ; i < size; i++)
    {
      if(copy[i] == true) //if vertices are active (not empty)
	{
	  cout << "  " << verts[i]; //print horizontal axis
	}
    }
  for(int i = 0; i < size; i++)
    {
      if(copy[i] == true) //if vertices are active
	{
	  cout << endl << verts[i]; //display vert axis
	  for(int k = 0; k < size; k++)
	    {
	      if(copy[k] == true)
		{
		  cout << "  " << array[i][k]; //print the edge data
		}
	    }
	}
    }
  return 1;
}

//remove vertex
int graph::remV(const char* label)
{
  int index = findIndex(label); //find the label for a vertex
  if(index == -1) //if -1 (empty), do nothing
    {
      return 0;
    }
  if(index < size) //if the index is within the size boundaries of the array
    {
      for(int i = 0; i < size; i++)
	{
	  array[index][i] = 0; //set all data values in both row and column of vertex to 0
	  array[i][index] = 0;
	}
      delete[] verts[index]; //delete the index
      copy[index] = false; //set the bool to false, making this vertex not display or be used
      return 1;
    }
  else //if not, do nothing
    {
      return 0;
    }
}

//add edge
int graph::addE(const char* l1, const char* l2, int weight)
{
  int index1 = findIndex(l1); //find index for 1st vertex
  int index2 = findIndex(l2); //find index for 2nd vertex
  
  if(index1 == -1 || index2 == -1) //if both indexes are empty (-1)
    {
      return 0; //do nothing
    }
  array[index1][index2] = weight; //set the 2D index to the weight int
  return 1;
}

//remove edge
int graph::remE(const char* l1, const char* l2)
{
  int index1 = findIndex(l1); //find indices
  int index2 = findIndex(l2);
  if(index1 == -1 || index2 == -1) //if empty, do nothing
    {
      return 0;
    }
  else //if not empty
    {
      array[index1][index2] = 0; //set edge to be 0 (no edge)
      return 1;
    }
}

//finds index
int graph::findIndex(const char* label)
{
  int index = 0;
  //if index is active, label matches with the vertex name, and within the boundaries
  while(copy[index] == true && strcmp(verts[index], label) != 0 && (index < size))
    {
      index++; //traverse
    }
  if(index < size) //when empty, but still inside the boundaries, return the index
    {
      return index;
    }
  else
    {
      return -1;
    }
}

//finds shortest path using Dijkstra's algorithm (Breadth-search)
int graph::findPath(const char* l1, const char* l2)
{
  int index1 = findIndex(l1); //find indices [ERROR]
  int index2 = findIndex(l2);
  if(index1 == -1 || index2 == -1) //if empty
    {
      return 0; //no edges
    }
  bool visit[size]; //bool array that stores whether or not the index has already been visited
  int dist[size]; //int array finding the distance
  int index[size]; //int array including the next index to traverse to

  //set up
  for(int i = 0; i < size; i++)
    {
      visit[i] = false; //nothing has been visited yet
      dist[i] = INT_MAX; //all distances will be set to "infinity"
      index[i] = -1; //-1 indicates the vertex we're on first
    }

  dist[index1] = 0; //dist of the 1st index is 0 to itself

  for(int i = 0; i < size - 1; i++)
    {
      int shortEdge = shortE(visit, dist); //finds the index

      visit[shortEdge] = true; //it's been visited, set to true
      for(int k = 0; k < size; k++)
	{
	  //if index k does not exist, array of [index][k] does, distance is not infinity, and the distances are not as big as infinity
	  if(!visit[k] && array[shortEdge][k] && dist[shortEdge] != INT_MAX && ((array[shortEdge][k] + dist[shortEdge]) < dist[k]))
	    {
	      index[k] = shortEdge; //set the index to the shortEdge index
	      dist[k] = array[shortEdge][k] + dist[shortEdge]; //set the distance to an amount less than infinity
	    }
	}
    }

  for(int i = 0; i < size; i++)
    {
      if(copy[i] == true)
      cout << visit[i] << " ";
    }
  cout << endl;
  for(int i = 0; i < size; i++)
    {
      if(copy[i] == true)
      cout << dist[i] << " ";
    }
  cout << endl;
  for(int i = 0; i < size; i++)
    {
      if(copy[i] == true)
      cout << index[i] << " ";
    }
  
  cout << "Path: " << verts[index1]; //lists out the first vertex visited
  printPath(index, index2); //then the other vertices visited
  if(dist[index2] != INT_MAX) //if dist[index2], or the weight of the entire path exists
    {
      cout << "\nWeight: " << dist[index2]; //gives the weight
      cout << "\nIndex1 = " << index1 << endl;
      cout << "Index2 = " << index2 << endl;
    }
  else //if it doesn't
    {
      cout << "\nWeight: N/A\n"; //indicates that there is no path
      cout << "Index1 = " << index1 << endl;
      cout << "Index2 = " << index2 << endl;
    }
}

//sets the short edge
int graph::shortE(bool visit[], int weight[])
{
  int min = INT_MAX; //the minimum initially set to infinity
  int index; 

  for(int i = 0; i < size; i++)
    {
      //if not visited yet, and the weight is less than infinity
      if(visit[i] == false && weight[i] < min)
	{
	  min = weight[i]; //set the weight to the number less than infinity
	  index = i; //set the index to where this is
	}
    }
  return index; //return the index
}

//prints the shortest path
void graph::printPath(int weight[], int index)
{
  if(weight[index] == -1) //if weight is -1/empty, do nothing
    {
      return;
    }
  else //if not,
    {
      printPath(weight, weight[index]); //recursively call function
      cout << " -> " << verts[index];
    }
}
