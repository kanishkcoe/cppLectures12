qu#include <iostream>
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

  ~Student()
  {
    cout << "Destructor called." << endl;
  }
};


//node definition
struct Node
{
  Student data;
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

  void enqueue(Student x);
  void dequeue();
  void printQueue();

};

void Queue::enqueue(Student x)
{
  //node creation
  Node *temp;
  temp = new Node;

  temp->data = x;

  temp->next = NULL;

  //if queue is empty
  if(front == NULL && rear == NULL)
  {
    front = temp;
    rear = temp;
    return;
  }

  //if queue is not empty
  rear->next = temp;
  rear = temp;
}

void Queue::dequeue()
{

  if(front == NULL && rear == NULL)
  {
    cout << "UnderFlow !" << endl;
    return;
  }

  Node *temp;

  temp = front;
  if(front == rear)
  {
    rear = rear->next;
  }
  front = front->next;

  cout << "Data to be deleted is : " << endl;
  (temp->data).show();
  delete temp;
}


void Queue::printQueue()
{
  Node * p; //traversal pointer

  p = front;

  while(p != NULL)
  {
    (p->data).show();
    p = p->next;
  }

  cout << "!!!!!!!!!!!!!!!" << endl;
}


int main()
{
  Queue q;

  Student x;
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
        x.get();
        q.enqueue(x);
        cout << "new word added to the queue" << endl;
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
