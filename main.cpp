#include"graph.h"

int main()
{
  graph g(20);
  char command[8];
  bool repeat = true;
  
  cout << "Weighted-Edge Directed Graph:";
  while(repeat == true)
    {
      cout << "\nADD or DELETE a vertex or edge, DISPLAY adjacency table, or PATH to find shortest path. EXIT to quit.\n";
      cin >> command;
      cin.ignore();

      for(int i = 0; i < strlen(command); i++)
	{
	  command[i] = toupper(command[i]);
	}
      
      if(strcmp(command, "ADD") == 0)
	{
	  char type[7];
	  cout << "Add a VERTEX or an EDGE?\n";
	  cin >> type;
	  cin.ignore();
	  
	  for(int i = 0; i <strlen(type); i++)
	    {
	      type[i] = toupper(type[i]);
	    }
	  
	  if(strcmp(type, "VERTEX") == 0)
	    {
	      char name[30];
	      cout << "Enter vertex name: ";
	      cin >> name;
	      cin.ignore();
	      for(int i = 0; i < strlen(name); i++)
		{
		  name[i] = toupper(name[i]);
		}
	      g.addV(name);
	    }
	  else if(strcmp(type, "EDGE") == 0)
	    {
	      char l1[30];
	      char l2[30];
	      int distance;
	      cout << "First vertex: ";
	      cin >> l1;
	      cin.ignore();
	      for(int i = 0; i < strlen(l1); i++)
		{
		  l1[i] = toupper(l1[i]);
		}
	      cout << "\nSecond vertex: ";
	      cin >> l2;
	      cin.ignore();
	      for(int i = 0; i < strlen(l2); i++)
		{
		  l2[i] = toupper(l2[i]);
		}
	      cout << "\nWeight: ";
	      cin >> distance;
	      g.addE(l1, l2, distance);  
	    }
	  else
	    {
	      cout << "Not a vertex or edge. Try again.\n";
	    }
	}
      else if(strcmp(command, "DELETE") == 0)
	{
	  char type[7];
	  cout << "Delete a VERTEX or an EDGE?\n";
	  cin >> type;
	  cin.ignore();

	  for(int i = 0; i < strlen(type); i++)
	    {
	      type[i] = toupper(type[i]);
	    }
	  
	  if(strcmp(type, "VERTEX") == 0)
	    {
	      char name[20];
	      cout << "Enter vertex name: ";
	      cin >> name;
	      
	      for(int i = 0; i < strlen(name); i++)
		{
		  name[i] = toupper(name[i]);
		}
	      g.remV(name);
	    }
	  else if(strcmp(type, "EDGE") == 0)
	    {
	      char l1[30];
	      char l2[30];
	      
	      cout << "First vertex: ";
	      cin >> l1;
	      cin.ignore();
	      for(int i = 0; i < strlen(l1); i++)
		{
		  l1[i] = toupper(l1[i]);
		}
	      cout << "\nSecond vertex: ";
	      cin >> l2;
	      cin.ignore();
	      for(int i = 0; i < strlen(l2); i++)
		{
		  l2[i] = toupper(l2[i]);
		}
	      g.remE(l1, l2);
	    }
	  else
	    {
	      cout << "Not a vertex or edge. Try again.\n";
	    }
	}
      else if(strcmp(command, "DISPLAY") == 0)
	{
	  cout << "Adjacency Table:\n";
	  g.display();
	}
      else if (strcmp(command, "PATH") == 0)
	{
	  char l1[30];
	  char l2[30];

	  cout << "First vertex: ";
	  cin >> l1;
	  cin.ignore();
	  for(int i = 0; i < strlen(l1); i++)
	    {
	      l1[i] = toupper(l1[i]);
	    }
	  cout << "Second vertex: ";
	  cin >> l2;
	  cin.ignore();
	  for(int i = 0; i < strlen(l2); i++)
	    {
	      l2[i] = toupper(l2[i]);
	    }
	  g.findPath(l1, l2);
	}
      else if(strcmp(command, "EXIT") == 0)
	{
	  cout << "\nExiting program.";
	  repeat = false;
	}
      else
	{
	  cout << "Command not found, try again.\n";
	}
    }
  return 0;
}
