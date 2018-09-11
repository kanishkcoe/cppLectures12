#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class CircularQueue
{
  int array[10];
  int front;
  int rear;
  int size;
public:

  CircularQueue()
  {
    front = 0;
    rear = 0;
    size = 10;
  }

  void insert(int x)
  {
    if((rear + 1) % size == front)
    {
      cout << "Overflow." << endl;
      return;
    }

    array[rear] = x;
    rear = (rear + 1) % size;
  }

  void remove()
  {
      if(front == rear)
      {
        cout << "Underflow!" << endl;
        return;
      }

      front = (front + 1) % size;
  }

  void printQueue()
  {
    for(int i = front; i != rear;  i = (i + 1) % size)
    {
        cout << array[i] << " ";
    }
    cout << "!!!" << endl;
  }
};

int main()
{
    CircularQueue s;

    int x;
    int choice;

    do
    {
      /* code */
      cout << "-==========================================-" << endl;
      cout << "MENU" << endl;
      cout << "1. insert" << endl;
      cout << "2. remove" << endl;
      cout << "3. print queue" << endl;
      cout << "4. exit" << endl;

      cout << "Enter choice : " << endl;
      cin >> choice;

      switch(choice)
      {
        case 1:
          cout << "Enter Data : " << endl;
          cin >> x;
          s.insert(x);
          break;
        case 2:
          s.remove();
          break;
        case 3:
          s.printQueue();
          break;
      }
    }
    while(choice != 4);

    cout << "program exited." << endl;

  return 0;
}
