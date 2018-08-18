#include <iostream>

using namespace std;

typedef struct Node * nodePointer;

struct Node
{
  int data;
  nodePointer link;
};

//global variable
nodePointer start = NULL;

nodePointer  createNode(int x)
{
  nodePointer temp;
  temp = new struct Node;

  temp->data = x;
  temp->link = NULL;

  return temp;
}

void insert_beginning(int x)
{
  nodePointer temp;
  temp = createNode(x);

  if(start == NULL)
  {
    //list is empty
    start = temp;
    return;
  }

  temp->link = start;
  start = temp;

}


void insert_end(int x)
{
  nodePointer  temp;
  temp = createNode(x);

  if(start == NULL)
  {
    //list is empty
    start = temp;
    return;
  }

  nodePointer p; //traversal pointer
  p = start;

  while(p->link != NULL)
  {
    p = p->link;
  }

  p->link = temp;
}

int deletion_beginning()
{
  if(start == NULL)
  {
    return -1;
  }

  nodePointer temp;
  temp = start;
  start = start->link;

  int x = temp->data;

  delete temp;

  return x;
}

int deletion_end()
{
  if(start == NULL)
  {
    cout << "list is empty." << endl;
    return -1;
  }

  nodePointer p;  //traversal nodePointer

  p = start;

  int x;

  if(p->link == NULL)
  {
    //only one node
    start = NULL;
    x = p->data;
    delete p;

    return x;
  }

  while(p->link->link != NULL && p->link != NULL)
  {
    p = p->link;
  }

  nodePointer temp;

  temp = p->link;
  x = temp->data;

  delete temp;

  p->link = NULL;

  return x;
}

void printList()
{
  nodePointer p; //traversal pointer

  p = start;

  while(p != NULL)
  {
    cout << p->data << " -> ";
    p = p->link;
  }

  cout << "!!!" << endl;
}

int main()
{
  int x = 0;

  while(x != -1)
  {
    cin >> x;

    if(x == -1)
        break;

    insert_end(x);
  }

  printList();

  cout << "deleted element = " << deletion_end() << endl;

  printList();

  return 0;
}
