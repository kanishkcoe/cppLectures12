#include <iostream>

using namespace std;

typedef struct Node * Nodeptr;

struct Node
{
  int data;
  Nodeptr next;
};

//global variable
Nodeptr start = NULL;


Nodeptr createNode(int x)
{
    Nodeptr temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}


void insert(int x)
{
  Nodeptr temp;
  temp = createNode(x);

  if(start == NULL)
  {
    start = temp;
    return;
  }

  temp->next = start;
  start = temp;
  return;
}


void printList()
{
    Nodeptr p; //traversal pointer

    p = start;


    while(p != NULL)
    {
      cout << p->data << " -> ";
      p = p->next;
    }

    cout << "!!!" << endl;
}


int main()
{
  int x = 0;

  cout << "Enter elements : " << endl;
  while(true)
  {
    cin >> x;
    if(x == -1)
      break;
    insert(x);
  }

  printList();
  return 0;
}
