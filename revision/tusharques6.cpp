#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct student
{
  int roll;
  char name[20];
};

struct node
{
  student data;
  node *next;
};

class Queue
{
  node *front;
  node *rear;

public:

  Queue()
  {
    front = NULL;
    rear = NULL;
  }
  void enqueue(student x)
  {
    node *temp;
    temp = new node;
    temp -> data = x;
    temp -> next = NULL;

    if(front == NULL && rear == NULL)
    {
      front = temp ;
      rear = temp;
      return;
    }

    rear -> next = temp;
    rear = temp;
  }

  void dequeue()
  {
    node *temp;

    if(front == NULL && rear == NULL)
    {
      cout<<"underflow"<<endl;
      return;
    }
    if(front == rear)
    {
      temp = front;
      front = front->next;
      rear = rear ->next;
      delete temp;
      return;
    }

    temp = front;
    front = front->next;
    delete temp;
  }

  void show()
  {
    node *p;
    student s;
    p = front;
    while(p != NULL)
    {
      cout<<"roll no : "<<p->data.roll<<endl;
      cout<<"name : "<<p->data.name<<endl;
      p=p->next;
    }
  }
};

int main()
{
  Queue q;
  student s;
  int choice;

  do
  {
    cout<<"1.enqueue"<<endl;
    cout<<"2.dequeue"<<endl;
    cout<<"3.show"<<endl;
    cout<<"4.exit"<<endl;

    cout<<"enter your choice"<<endl;
    cin>>choice;

    switch (choice)
    {
      case 1 : cout<<"enter roll no"<<endl;
               cin>>s.roll;
               cout<<"enter name"<<endl;
               cin.ignore();
               cin.getline(s.name , sizeof(s.name));
               q.enqueue(s);
               break;

      case 2 : q.dequeue();
               break;

      case 3 : q.show();
               break;
    }
  }while(choice != 4);

  return 0;
}
