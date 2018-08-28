e#include <iostream>

using namespace std;

struct Stack
{
  int data;
  struct Stack *next;
};


//top pointer
struct Stack *top = NULL;


void push(int x)
{
  Stack *temp;
  temp = new struct Stack;

  temp->data = x;
  temp->next = NULL;

  if(top == NULL)
  {
    top = temp;
    return;
  }

  temp->next = top;
  top = temp;
}


int pop()
{
  int x = -1;

  if(top == NULL)
  {
    return x;
  }

  Stack *temp;
  temp = top;

  x = temp->data;
  top = top->next;

  delete temp;

  return x;
}


int peak()
{
  int x = -1;

  if(top == NULL)
  {
    return x;
  }

  x = top->data;

  return x;
}


void printStack()
{
  Stack *p;

  p = top;

  while(p != NULL)
  {
    cout << p->data << endl;
    p = p->next;
  }

  cout << "________" << endl;
}


int main()
{

  int number;
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
        cout << "Enter number : "; cin >> number;
        push(number);
        cout << number << " pushed in the list." << endl;
        break;
      case 2:
        number = pop();
        if(number != -1)
          cout << number << " popped." << endl;
        else
          cout << "Stack is empty." << endl;
        break;
      case 3:
        if(peak() != -1)
          cout << peak() << " is the peak element." << endl;
        else
          cout << "Stack is empty." << endl;
        break;
      case 4:
        printStack();
        break;
    }
  }
  while(choice != 5);

  cout << "program exited." << endl;
  return 0;
}
