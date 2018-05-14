#include "gdc.h"

gdc::gdc()
{
  head = NULL;
}

gdc::~gdc()
{
  //do something later
}

int gdc::addVert(int id)
{
  return addVert(head, id);
}

int gdc::addVert(node* &head, int id)
{
  node* newNode = new node;
  
