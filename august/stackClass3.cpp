#include <iostream>

using namespace std;


struct Employee
{
  int eno;
  char name[20];
};


struct Node
{
    Employee data;
    Node * next;
};

class Stack
{
  Node * top;

public:
  Stack()
  {
    top = NULL;
  }

  void push(Employee x);
  void pop();
  void peak();
  void printStack();
};

void Stack::push(Employee x)
{
  //creation of the Node
  Node * temp;
  temp = new Node;

  temp->data = x;
  temp->next = NULL;

  //if Stack is empty
  if(top == NULL)
  {
    top = temp;
    return;
  }

  //if stack is not empty
  temp->next = top;
  top = temp;

}

void Stack::pop()
{
  if(top == NULL)
  {
    cout << "Underflow!" << endl;
    return;
  }

  Node * temp;
  temp = top;

  top = top->next;

  cout << "Data deleted is : " << endl;
  cout << "Eno = " << (temp->data).eno << endl;
  cout << "Name = " << (temp->data).name << endl;

  delete temp;
}

void Stack::peak()
{
  if(top == NULL)
  {
    cout << "Underflow!" << endl;
    return;
  }

  cout << "Data on the top is : " << endl;
  cout << "Eno = " << (top->data).eno << endl;
  cout << "Name = " << (top->data).name << endl;
}

void Stack::printStack()
{
  Node * p;

  for(p = top; p != NULL; p = p->next)
  {
    cout << "-------------------------------" << endl;
    cout << "Eno = " << (p->data).eno << endl;
    cout << "Name = " << (p->data).name << endl;
    cout << "-------------------------------" << endl;
  }

  cout << "+-------------------------------------------+" << endl;
}

int main()
{
  Stack s;

  Employee x;
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
        cout << "Enter eno : "; cin >> x.eno;
        cin.ignore();
        cout << "Enter name : "; cin.getline(x.name, sizeof(x.name));
        s.push(x);
        cout << "Data is pushed to the stack." << endl;
        break;
      case 2:
        s.pop();
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

  return 0;
}
