#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 5

struct Student
{
  int roll;
  char name[20];
};

class Queue
{
  int front;
  int rear;
  Student data[MAX];

public:
  Queue()
  {
    front = -1;
    rear = 0;
  }
  void enqueue(Student x);
  void dequeue();
  void show();
};

void Queue::enqueue(Student x)
{
  if(rear == MAX)
  {
    cout << "overflow" << endl;
    return;
  }

  data[rear] = x;
  rear++;
}

void Queue::dequeue()
{
  if(front + 1 == rear)
  {
    cout << "underflow" << endl;
    front = -1;
    rear = 0;
    return;
  }

  front++;
}


void Queue::show()
{
  for(int i = front + 1; i < rear; i++)
  {
    cout << data[i].roll << " - " << data[i].name << endl;
  }
}


int main()
{

  Queue q;
  Student x;

  int choice;

  do
  {
    cout << "__________________MENU_________________" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
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

        q.enqueue(x);
        break;

      case 2:
        q.dequeue();
        break;

      case 3:
        q.show();
        break;
    }

  } while(choice != 4);

  return 0;
}
