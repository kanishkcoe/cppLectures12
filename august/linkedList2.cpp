#include <iostream>

using namespace std;

struct Node
{
  int data;
  struct Node *link;
};

//global variable
struct Node *start = NULL;

struct Node * createNode(int x)
{
  struct Node *temp;
  temp = new struct Node;

  temp->data = x;
  temp->link = NULL;

  return temp;
}

void insert(int x)
{
  struct Node *temp;
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

void printList()
{
  struct Node *p; //traversal pointer

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

    insert(x);
  }

  printList();

  return 0;
}
