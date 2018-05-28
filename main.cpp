#include"graph.h"

const int SIZE = 50;

int main()
{
  graph g(20);
  char command[8];
  bool repeat = true;
  
  cout << "Weighted-Edge Directed Graph:";
  while(repeat == true) //loop while true
    {
      cout << "\nADD or DELETE a vertex or edge, DISPLAY adjacency table, or PATH to find shortest path. EXIT to quit.\n";
      cin >> command; //command input
      cin.ignore();

      //make command all caps
      for(int i = 0; i < strlen(command); i++)
	{
	  command[i] = toupper(command[i]);
	}

      //add a vertex or an edge
      if(strcmp(command, "ADD") == 0)
	{
	  char type[SIZE];
	  cout << "Add a VERTEX or an EDGE?\n";
	  cin.get(type, SIZE, '\n');
	  cin.ignore(SIZE, '\n');
	  
	  for(int i = 0; i <strlen(type); i++)
	    {
	      type[i] = toupper(type[i]);
	    }
	  
	  if(strcmp(type, "VERTEX") == 0)
	    {
	      char name[SIZE];
	      cout << "Enter vertex name: ";
	      cin.get(name, SIZE, '\n');
	      cin.ignore(SIZE, '\n');
	      for(int i = 0; i < strlen(name); i++)
		{
		  name[i] = toupper(name[i]);
		}
	      g.addV(name);
	    }
	  else if(strcmp(type, "EDGE") == 0)
	    {
	      char l1[SIZE];
	      char l2[SIZE];
	      int distance;
	      cout << "First vertex: ";
	      cin.get(l1, SIZE, '\n');
	      cin.ignore(SIZE, '\n');
	      for(int i = 0; i < strlen(l1); i++)
		{
		  l1[i] = toupper(l1[i]);
		}
	      cout << "\nSecond vertex: ";
	      cin.get(l2, SIZE, '\n');
	      cin.ignore(SIZE, '\n');
	      for(int i = 0; i < strlen(l2); i++)
		{
		  l2[i] = toupper(l2[i]);
		}
	      cout << "\nWeight: ";
	      cin >> distance;
	      //adds edge, unless it doesn't exist
	      if(g.addE(l1, l2, distance) == 0)
		{
		  cout << "An edge can't be put there!\n";
		}
	    }
	  else
	    {
	      cout << "Not a vertex or edge. Try again.\n";
	    }
	}
      //delete vertex/edge
      else if(strcmp(command, "DELETE") == 0)
	{
	  char type[SIZE];
	  cout << "Delete a VERTEX or an EDGE?\n";
	  cin.get(type, SIZE, '\n');
	  cin.ignore(SIZE, '\n');

	  for(int i = 0; i < strlen(type); i++)
	    {
	      type[i] = toupper(type[i]);
	    }
	  
	  if(strcmp(type, "VERTEX") == 0)
	    {
	      char name[SIZE];
	      cout << "Enter vertex name: ";
	      cin.get(name, SIZE, '\n');
	      
	      for(int i = 0; i < strlen(name); i++)
		{
		  name[i] = toupper(name[i]);
		}
	      if(g.remV(name) == 0)
		{
		  cout << "Vertex does not exist!\n";
		}
	    }
	  else if(strcmp(type, "EDGE") == 0)
	    {
	      char l1[SIZE];
	      char l2[SIZE];
	      
	      cout << "First vertex: ";
	      cin.get(l1, SIZE, '\n');
	      cin.ignore(SIZE, '\n');
	      for(int i = 0; i < strlen(l1); i++)
		{
		  l1[i] = toupper(l1[i]);
		}
	      cout << "\nSecond vertex: ";
	      cin.get(l2, SIZE, '\n');
	      cin.ignore(SIZE, '\n');
	      for(int i = 0; i < strlen(l2); i++)
		{
		  l2[i] = toupper(l2[i]);
		}
	      if(g.remE(l1, l2) == 0)
		{
		  cout << "There's no edge there!\n";
		}
	    }
	  else
	    {
	      cout << "Not a vertex or edge. Try again.\n";
	    }
	}
      //display adj table
      else if(strcmp(command, "DISPLAY") == 0)
	{
	  cout << "Adjacency Table:\n";
	  g.display();
	}
      //find shortest path using breadth first search
      else if (strcmp(command, "PATH") == 0)
	{
	  char l1[SIZE];
	  char l2[SIZE];

	  cout << "First vertex: ";
	  cin.get(l1, SIZE, '\n');
	  cin.ignore(SIZE, '\n');
	  for(int i = 0; i < strlen(l1); i++)
	    {
	      l1[i] = toupper(l1[i]);
	    }
	  cout << "Second vertex: ";
	  cin.get(l2, SIZE, '\n');
	  cin.ignore(SIZE, '\n');
	  for(int i = 0; i < strlen(l2); i++)
	    {
	      l2[i] = toupper(l2[i]);
	    }
	  if(g.findPath(l1, l2) == 0)
	    {
	      cout << "Path doesn't exist!\n";
	    }
	}
      //quit program
      else if(strcmp(command, "EXIT") == 0)
	{
	  cout << "\nExiting program.";
	  repeat = false; //ends loop
	}
      else
	{
	  cout << "Command not found, try again.\n";
	}
    }
  return 0;
}
