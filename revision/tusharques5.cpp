#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 10

class Queue
{
  int front;
  int rear;
  int data[MAX];
public:
  Queue()
  {
    front = -1;
    rear = 0;
  }

  void enqueue(int x)
  {
    if (rear == MAX)
    {
      cout<<"overflow"<<endl;
      return;
    }
    data[rear] = x;
    rear++;
  }
  void dequeue()
  {
    if(front + 1 == rear)
    {
      cout<<"underflow"<<endl;
      front = -1;
      rear = 0;
      return;
    }

    front++;
  }
  void show()
  {
    for(int i = front +1; i<rear ; i++)
    {
      cout<<endl<<data[i]<<endl;
    }
  }
};
int main()
{
  int choice , ele;
  Queue q;
  do
{
  cout<<"1.enqueue"<<endl;
  cout<<"2.dequeue"<<endl;
  cout<<"3.show"<<endl;
  cout<<"4.exit"<<endl;

  cout<<"enter choice "<<endl;
  cin>>choice;

  switch(choice)
{
  case 1 :
           cout<<"Enter element"<<endl;
           cin>>ele;
           q.enqueue(ele);
           break;

  case 2 : q.dequeue();
           break;

  case 3 : q.show();
           break;
}
}while(choice !=4);

  return 0;
}
