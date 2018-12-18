#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 10

struct Student
{
  int roll;
  char name[20];
};

class Stack
{
  int top;
  Student data[MAX];

public:
  Stack()
  {
    top = -1;
  }
  void push(Student x);
  void pop();
  void show();
};

void Stack::push(Student x)
{
  if(top == MAX - 1)
  {
    cout << "overflow!" << endl;
    return;
  }

  top++;
  data[top] = x;
}

void Stack::pop()
{
  if(top == - 1)
  {
    cout << "underflow!" << endl;
    return;
  }

  top--;
}

void Stack::show()
{
  for(int i = top; i >= 0; i--)
  {
    cout << data[i].roll << " - " << data[i].name << endl;
  }
}


int main()
{

  Stack s;
  Student x;

  int choice;

  do
  {
    cout << "__________________MENU_________________" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Show" << endl;
    cout << "4. Quit" << endl;

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
      case 1:
        cout << "Enter roll number : ";
        cin >> x.roll;

        cin.ignore();
        
        cout << "Enter name : ";
        cin.getline(x.name, sizeof(x.name));

        s.push(x);
        break;

      case 2:
        s.pop();
        break;

      case 3:
        s.show();
        break;
    }

  } while(choice != 4);

  return 0;
}
