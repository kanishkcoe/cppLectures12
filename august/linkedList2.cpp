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

  return 0;
}
