#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 5

struct student
{
  int roll;
  char name[20];
};

class Stack
{
  int top;
  student data[MAX];
public:
  Stack()
  {
    top=-1;
  }

  void push(student x);
  void pop();
  void show();
};

 void Stack::push(student x)
 {
   if(top == MAX -1)
   {
     cout<<"overflow"<<endl;
     return;
   }

   top++;
   data[top]=x;
 }
 void Stack::pop()
 {
   if(top == -1)
   {
     cout<<"underflow"<<endl;
     return;
   }

   top--;
 }

void Stack::show()
{
for(int i = top; i >=0 ; i--)
  {
    cout<<data[i].roll<<"--"<<data[i].name<<endl;
  }
}
int main()
{
  Stack s;
  student x;
  int choice;

  do {
    cout<<"___________________menu________________"<<endl;
    cout<<"1.push"<<endl;
    cout<<"2.pop"<<endl;
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
               s.push(x);
               break;
      case 2 : s.pop();
               break;
      case 3 : s.show();
               break;
    }
  } while(choice != 4);

  return 0;
}
