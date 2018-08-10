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


void insert_beginning(int x)
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

void insert_end(int x)
{
  Nodeptr temp;
  temp = createNode(x);

  //if list is empty
  if(start == NULL)
  {
    start = temp;
    return;
  }


  Nodeptr p;
  p = start;

  while(p->next != NULL)
  {
    p = p->next;
  }

  p->next = temp;
}


int deletion_beginning()
{
    //if list is empty
    if(start == NULL)
    {
      cout << "List is empty." << endl;
      return -1;
    }

    Nodeptr temp;
    int number;

    temp = start;
    start = start->next;
    number = temp->data;

    delete temp;
    return number;
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
    insert_end(x);
  }

  printList();

  cout << "deleted data = " << deletion_beginning() << endl;

  printList();
  return 0;
}
