#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class book
{
public:
  int id;
  char name[10];
};

struct node
{
  book data;
  node *next;
};

class Stack
{
  node *top;

public:

  Stack()
  {
    top = NULL;
  }

  void push(int id , char name[])
  {
    node *temp;

    temp = new node;
    temp->data.id = id;
    strcpy(temp->data.name , name);
    temp->next = NULL;

    if(top == NULL)
    {
      top = temp;
      return;
    }

    top= temp;
    top->next = NULL;
  }

  void pop()
  {
    node *temp;

    if(top == NULL)
    {
      cout<<"underflow"<<endl;
      return;
    }

    temp = top;
    top = top->next;
    delete temp;
  }

  void show()
  {
    node *p;

    p = top;
    while(p != NULL)
    {
      cout<<"id - "<<p->data.id<<endl;
      cout<<"name - "<<p->data.name<<endl;
      p = p->next;
    }
  }
};

int main()
{
  Stack s;
  int id;
  char name[20];
  int choice;

do
{
  cout<<"1.push"<<endl;
  cout<<"2.pop"<<endl;
  cout<<"3.show"<<endl;
  cout<<"4.exit"<<endl;

  cout<<"enter choice"<<endl;
  cin>>choice;

  switch(choice)
  {
    case 1 : cout<<"enter id"<<endl;
             cin>>id;
             cout<<"enter name"<<endl;
             cin.ignore();
             cin.getline(name , sizeof(name));
             s.push(id,name);
             break;

    case 2 : s.pop();
             break;

    case 3 : s. show();
             break;

  }
}while(choice != 4);
  return 0;
}
