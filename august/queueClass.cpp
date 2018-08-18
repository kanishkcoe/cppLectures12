#include <iostream>
#include <string.h>

using namespace std;

//node definition
struct Node
{
  char *data;
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

  void enqueue(char *x);
  char *dequeue();
  void printQueue();

};

void Queue::enqueue(char *x)
{
  //node creation
  Node *temp;
  temp = new Node;

  temp->data = new char[strlen(x) + 1];
  strcpy(temp->data, x);
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

char * Queue::dequeue()
{

  if(front == NULL && rear == NULL)
  {
    cout << "UnderFlow !" << endl;
    return "NONE";
  }

  char *x;
  x = front->data;

  Node *temp;

  temp = front;
  front = front->next;

  delete temp;
  return x;
}


void Queue::printQueue()
{
  Node * p; //traversal pointer

  p = front;

  while(p != NULL)
  {
    cout << p->data << " <-- ";
    p = p->next;
  }

  cout << "!!!" << endl;
}


int main()
{
  Queue q;

  char word[50];
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
        cout << "Enter Word to the queue : " << endl;
        cin.ignore();
        cin.getline(word, sizeof(word));
        q.enqueue(word);
        cout << "new word added to the queue" << endl;
        break;
      case 2:
        strcpy(word, q.dequeue());
        cout << word << " deleted from the queue." << endl;
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
