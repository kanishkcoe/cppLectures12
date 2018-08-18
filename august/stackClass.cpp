//implementation of stack with complex data using class

#include <iostream>
#include <string.h>

using namespace std;

class Student
{
  int roll_number;
  char name[20];

public:
  Student()
  {
    roll_number = 0;
    strcpy(name, "NONE");
  }

  Student(Student &obj)
  {
    roll_number = obj.roll_number;
    strcpy(name, obj.name);
    cout << "Copy constructor called." << endl;
  }

  void get()
  {
    cout << "Enter roll number : ";
    cin >> roll_number;
    cin.ignore();
    cout << "Enter name : ";
    cin.getline(name, sizeof(name));
  }

  void show()
  {
    cout << "--------------------------------" << endl;
    cout << "Roll number : " << roll_number << endl;
    cout << "Name : " << name << endl;
    cout << "--------------------------------" << endl;
  }

};


struct Node
{
    Student data;
    struct Node *next;
};

class Stack
{
    struct Node *top;

  public:
    Stack()
    {
      top = NULL;
    }

    void push(Student x);
    void pop();
    Student peak();
    void printStack();

    ~Stack()
    {
        cout << "Stack pointer deleted." << endl;
        Node *temp;

        while(top != NULL)
        {
          temp = top;
          top = top->next;

          delete temp;
        }

        delete top;
    }
};

//member function definitions

void Stack::push(Student x)
{
  Node *temp;
  temp = new struct Node;

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

void Stack::pop()
{
  Student x;

  if(top == NULL)
  {
    cout << "No Student in the Stack!" << endl;
    return;
  }

  //cout << "here" << endl;
  Node *temp;
  temp = top;

  x = temp->data; // due to copy constructor
  top = top->next;

  delete temp;

  cout << "Data of Student Deleted : " << endl;
  x.show();
}

Student Stack::peak()
{
  Student x;

  if(top == NULL)
  {
    return x;
  }

  x = top->data;

  return x;
}


void Stack::printStack()
{
  Node *p;

  p = top;

  while(p != NULL)
  {
    (p->data).show();
    p = p->next;

  }
  cout << "________" << endl;
}

int main()
{
  Stack s;

  Student object;
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
        cout << "Enter Data of student : " << endl;
        object.get();
        s.push(object);
        break;
      case 2:
        s.pop();
        //cout << "here" << endl;
        break;
      case 3:
        object = s.peak();
        cout << "Data on the top : " << endl;
        object.show();
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
