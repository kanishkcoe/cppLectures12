#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 5

struct student
{
  int roll;
  char name[20];
};

class Queue
{
  int front;
  int rear;
  student data[MAX];
public:
  Queue()
  {
    front = -1;
    rear = 0;
  }

  void enqueue(student x);
  void dqueue();
  void show();
};

 void Queue::enqueue(student x)
 {
   if(rear == MAX)
   {
     cout<<"overflow"<<endl;

     return;
   }

   data[rear] = x;
   rear++;
 }
 void Queue::dqueue()
 {
   if(front == rear -1)
   {
     cout<<"underflow"<<endl;
     front=-1;
     rear=0;
     return;
   }

   front ++;
 }

void Queue::show()
{
for(int i = front + 1; i <rear ; i++)
  {
    cout<<data[i].roll<<"--"<<data[i].name<<endl;
  }
}
int main()
{
  Queue s;
  student x;
  int choice;

  do {
    cout<<"___________________menu________________"<<endl;
    cout<<"1.enqueue"<<endl;
    cout<<"2.dqueue"<<endl;
    cout<<"3.show"<<endl;
    cout<<"4.quit"<<endl;
    cout<<"enter choice:";
    cin>>choice;

    switch (choice)
    {
      case 1 : cout<<"enter roll:";
               cin>>x.roll;
               cin.ignore();
               cout<<"enter name";
               cin.getline(x.name, sizeof(x.name));
               s.enqueue(x);
               break;
      case 2 : s.dqueue();
               break;
      case 3 : s.show();
               break;
    }
  } while(choice != 4);

  return 0;
}
