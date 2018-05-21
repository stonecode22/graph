#include"graph.h"

int main()
{
  graph g(20);

  g.addV("one");
  g.addV("two");
  g.addV("three");
  g.addV("four");
  g.display();
  g.addE("one", "three", 7);
  g.addE("three", "two", 3);
  g.addE("one", "four", 1);
  g.addE("four", "two", 2);
  cout << endl;
  g.display();
  g.findPath("one", "two");
  return 1;
}
