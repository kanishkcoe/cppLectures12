#include <iostream>
#include <string.h>

using namespace std;


struct Node
{
    char data[20];
    Node *next;
};

class Stack
{
  Node *top;

public:

  Stack()
  {
    top = NULL;
    cout << "Constructor called." << endl;
  }

  void push(char *x)
  {
    //Node creation
    Node *temp;
    temp = new Node;
    strcpy(temp->data, x);
    temp->next = NULL;

    //check if stack is empty or not
    if(top == NULL)
    {
      cout << "Stack was empty." << endl;
      top = temp;
      return;
    }

    //stack is not empty
    temp->next = top;
    top = temp;
  }

  char *pop()
  {
    if(top == NULL)
    {
      cout << "Stack is empty." << endl;
      return "NONE";
    }


    char *x;
    x = new char[20];
    Node *temp;
    temp = top;

    strcpy(x, temp->data);
    top = top->next;


    delete temp;

    return x;
  }


  char *peak()
  {
    if(top == NULL)
    {
      cout << "Stack is empty." << endl;
      return "NONE";
    }

    Node *temp;
    temp = top;

    return temp->data;
  }

  void printStack()
  {
    Node *p;
    p = top;

    while(p != NULL)
    {
      cout << p->data << endl;
      p = p->next;
    }

    cout << "_________" << endl;
  }

};

int main()
{
  Stack s;

  char x[20];
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
        cout << "Enter string : " << endl;
        cin.ignore();
        cin.getline(x, sizeof(x));
        s.push(x);
        cout << x << " is pushed to the stack." << endl;
        break;
      case 2:
        strcpy(x, s.pop());
        cout << x << " is popped from the stack." << endl;
        break;
      case 3:
        strcpy(x, s.peak());
        cout << "Data on the top : " << x << endl;
        break;
      case 4:
        s.printStack();
        break;
    }
  }
  while(choice != 5);

  cout << "program exited." << endl;

  return 0;
}
