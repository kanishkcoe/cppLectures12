#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 10

class Stack
{
  int top;
  int data[MAX];
public:
  stack()
  {
    top = -1;
  }

  void push(int x)
  {
    if (top == MAX - 1)
    {
      cout<<"overflow"<<endl;
      return;
    }
    top++;
    data[top] = x;
  }
  void pop()
  {
    if(top == -1)
    {
      cout<<"underflow"<<endl;
      return;
    }

    top--;
  }
  void show()
  {
    for(int i =0; i<=top ; i++)
    {
      cout<<data[i]<<endl;
    }
  }
};
int main()
{
  int choice , ele;
  Stack s;
  do
{
  cout<<"1.push"<<endl;
  cout<<"2.pop"<<endl;
  cout<<"3.show"<<endl;
  cout<<"4.exit"<<endl;

  cout<<"enter choice "<<endl;
  cin>>choice;

  switch(choice)
{
  case 1 :
           cout<<"Enter element"<<endl;
           cin>>ele;
           s.push(ele);
           break;

  case 2 : s.pop();
           break;

  case 3 : s.show();
           break;
}
}while(choice !=4);

  return 0;
}
