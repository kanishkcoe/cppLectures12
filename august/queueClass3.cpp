#include <iostream>

using namespace std;

//data is a structure
struct Employee
{
  int eno;
  char name[20];
  float salary;
};


struct Node
{
  Employee data;
  Node *next;
};


class Queue
{
  Node *front;
  Node *rear;

public:
  Queue()
  {
    front = NULL;
    rear = NULL;
  }

  void enqueue(Employee x)
  {
    //insert to the end
    //node creation

    Node *temp;
    temp = new Node;

    temp->data = x;
    temp->next = NULL;

    //if queue is empty?
    if(front == NULL && rear == NULL)
    {
      front = temp;
      rear = temp;
      return;
    }

    rear->next = temp;
    rear = temp;
  }

  void dequeue()
  {
    if(front == NULL && rear == NULL)
    {
      cout << "Underflow!" << endl;
      return;
    }

    Node *temp;
    temp = front;

    if(front == rear)
    {
      front = NULL;
      rear = NULL;
      cout << "Data deleted is : " << endl;
      cout << "Employee number = " << (temp->data).eno << endl;
      cout << "Employee name = " << (temp->data).name << endl;
      cout << "Employee salary = " << (temp->data).salary << endl;
      delete temp;
      return;
    }

    front = front->next;

    cout << "Data deleted is : " << endl;
    cout << "Employee number = " << (temp->data).eno << endl;
    cout << "Employee name = " << (temp->data).name << endl;
    cout << "Employee salary = " << (temp->data).salary << endl;

    delete temp;
  }

  void printQueue()
  {
    Node *p;

    p = front;

    while(p != NULL)
    {
      cout << "------------------------------------------------" << endl;
      cout << "Employee number = " << (p->data).eno << endl;
      cout << "Employee name = " << (p->data).name << endl;
      cout << "Employee salary = " << (p->data).salary << endl;
      cout << "------------------------------------------------" << endl;

      p = p->next;
    }
  }
};

int main()
{
  Queue q;
  Employee x;
  int choice;

  do
  {
    /* code */
    cout << "-==========================================-" << endl;
    cout << "MENU" << endl;
    cout << "1. enqueue" << endl;
    cout << "2. dequeue" << endl;
    cout << "3. print queue" << endl;
    cout << "4. exit" << endl;

    cout << "Enter choice : " << endl;
    cin >> choice;

    switch(choice)
    {
      case 1:
        cout << "Enter Data to the queue : " << endl;
        cout << "Enter eno : "; cin >> x.eno;
        cin.ignore();
        cout << "Enter name : "; cin.getline(x.name, sizeof(x.name));
        cout << "Enter salary : "; cin >> x.salary;
        q.enqueue(x);
        cout << "new data added to the queue" << endl;
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        q.printQueue();
        break;
    }
  }
  while(choice != 4);

  cout << "program exited." << endl;

  return 0;
}
