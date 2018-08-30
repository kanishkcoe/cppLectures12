#include <iostream>
#define MAX 10

using namespace std;


class Stack
{
  int top;
  int data[MAX];

public:
  Stack()
  {
    top = -1;
  }

  void push(int x)
  {
    if(top == MAX - 1)
    {
      cout << "Overflow!" << endl;
      return;
    }

    top++;
    data[top] = x;
  }

  void pop()
  {
    if(top == -1)
    {
      cout << "Underflow!" << endl;
      return;
    }

    cout << data[top] << " popped." << endl;
    top--;
  }

  void peak()
  {
    if(top == -1)
    {
      cout << "Underflow!" << endl;
      return;
    }

    cout << data[top] << " on the top." << endl;
  }

  void printStack()
  {
    for(int i = top; i >= 0; i--)
    {
      cout << data[i] << endl;
    }
    cout << "_______" << endl;
  }
};


int main()
{
  Stack s;

  int x;
  int choice;

  do
  {
    /* code */
    cout << "-==========================================-" << endl;
    cout << "MENU" << endl;
    cout << "1. push" << endl;
    cout << "2. pop" << endl;
    cout << "3. peak" << endl;
    cout << "4. print stack" << endl;
    cout << "5. exit" << endl;

    cout << "Enter choice : " << endl;
    cin >> choice;

    switch(choice)
    {
      case 1:
        cout << "Enter Data : " << endl;
        cin >> x;
        s.push(x);
        break;
      case 2:
        s.pop();
        //cout << "here" << endl;
        break;
      case 3:
        s.peak();
        break;
      case 4:
        s.printStack();
        break;
    }
  }
  while(choice != 5);

  cout << "program exited." << endl;
}
