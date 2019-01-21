#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
  int eno;
  char ename[20];
  float salary;

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

  void push(int eno ,char ename[] , float salary)
  {
    node *temp;
    temp = new node;

    temp->eno = eno;

    strcpy(temp->ename , ename);

    temp->salary = salary;

    temp->next = NULL;

    if(top == NULL)
    {
      top = temp;
      return;
    }

    temp->next = top;
    top = temp;
  }

  void pop()
  {
    if(top == NULL)
    {
      cout<<"underflow"<<endl;
      return;
    }

    node *temp;
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
      cout<<"eno : "<<p->eno<<endl;
      cout<<"ename : "<<p->ename<<endl;
      cout<<"salary : "<<p->salary<<endl;
      p = p->next;
    }
  }

};

int main()
{
  int choice;
  int eno;
  char ename[20];
  float salary;
  Stack s;

  do
  {
    cout<<"1.push"<<endl;
    cout<<"2.pop"<<endl;
    cout<<"3.show"<<endl;
    cout<<"4.exit"<<endl;

    cout<<"enter your choice"<<endl;
    cin>>choice;
    switch (choice)
    {
      case 1: cout<<"enter eno : "<<endl;
              cin>>eno;
              cout<<"enter name"<<endl;
              cin.ignore();
              cin.getline(ename , sizeof(ename));
              cout<<"enter salary"<<endl;
              cin>>salary;

              s.push(eno , ename ,salary);
              break;

      case 2 : s.pop();
               break;
      case 3 : s.show();a
               break;
    }
  } while(choice != 4);

  return 0;
}
