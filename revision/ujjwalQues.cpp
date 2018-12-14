#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

class LinkedList
{
  Node *start;

public:

  LinkedList()
  {
    start = NULL;
  }

  void ncreate(int n)
  {
    Node * temp;
    int num;

    temp = new Node;
    cout << "Enter data : ";
    cin >> num;

    temp->data = num;
    temp->next = NULL;

    //first node created
    start = temp;

    //now we are left with n - 1 nodes

    for(int i = 0; i < n - 1; i++)
    {
      temp = NULL;
      temp = new Node;
      cout << "Enter data : ";
      cin >> num;
      temp->data = num;
      temp->next = NULL;

      temp->next = start;
      start = temp;
    }
  }

  void display()
  {
    Node *p;

    p = start;

    while(p != NULL)
    {
      cout << p->data << "---->";
      p = p->next;
    }

    cout << "!!!" << endl;
  }

  void insert(int k)
  {
    Node * temp;
    int num;

    temp = new Node;
    cout << "Enter data : ";
    cin >> num;

    temp->data = num;
    temp->next = NULL;

    Node *p;
    Node *n;

    p = start;
    n = start->next;

    for(int i = 1; i < k-1; i++)
    {
      p = p->next;
      n = n->next;
    }

    temp->next = n;
    p->next = temp;
  }
};


int main()
{

  LinkedList list;

  int n;
  cout << "Enter number of nodes : ";
  cin >> n;

  list.ncreate(n);

  list.display();


  int k;
  cout << "Enter k of node : ";
  cin >> k;

  list.insert(k);

  list.display();

  return 0;
}
