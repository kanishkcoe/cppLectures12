#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  node *next;
};

class Linkedlist
{
  node *front;
  node *rear;
public:

  Linkedlist()
  {
    front = NULL;
    rear = NULL;
  }

  node *getfront()
  {
    return front;
  }
  node *getrear()
  {
    return rear;
  }

  void insert_beg()
  {
    int x;
    cout<<"enter the element"<<endl;
    cin>>x;
    node *temp;
    temp = new node;
    temp->data = x;
    temp->next = NULL;

    if(front== NULL && rear == NULL)
    {
      front = temp;
      rear = temp;
      return;
    }

    temp->next = front;
    front = temp;
  }
  void insert_beg2(int x)
  {
    node *temp;
    temp = new node;
    temp->data = x;
    temp->next = NULL;

    if(front== NULL && rear == NULL)
    {
      front = temp;
      rear = temp;
      return;
    }

    temp->next = front;
    front = temp;
  }
  void insert_end(int x)
  {
    node *temp;
    temp = new node;
    temp->data = x;
    temp->next = NULL;

    if(front== NULL && rear == NULL)
    {
      front = temp;
      rear = temp;
      return;
    }

    rear->next = temp;
    rear = temp;
  }
  void delete_beg()
  {
    node *temp;
    int x;

    if(front== NULL && rear == NULL)
    {
      cout<<"underflow"<<endl;
      return;
    }

    if(front->next == NULL)
    {
      rear = NULL;
    }

    temp = front;
    front=front->next;
    x= temp->data;
    delete temp;
  }

  void delete_end()
  {
    node *p;
    p=front;
    node *temp;

    while((p->next)->next != NULL)
    {
      p=p->next;
    }

    temp = p->next;

    delete temp ;
    p->next=NULL;
  }

  void traverse()
  {
    node *p;
    p=front;
    while(p->next != NULL)
    {
      cout<<p->data<<"  ";
      p=p->next;
    }
    cout<<p->data<<endl;
  }

  void insert_aft(int a)
  {
    int data;
    node *newdata;
    cout<<"enter the new integer"<<endl;
    cin>>data;
    newdata = new node;
    newdata->data=data;
    newdata->next=NULL;
    node *p;
    p=front;
    while(p->data != a)
    {
      p=p->next;
    }
    newdata->next=p->next;
    p->next=newdata;
  }

  void insert_bef(int a)
  {
    int data;
    node *newdata;
    cout<<"enter the new integer"<<endl;
    cin>>data;
    newdata = new node;
    newdata->data=data;
    newdata->next=NULL;
    node *p;
    p=front;
    while((p->next)->data != a)
    {
      p=p->next;
    }
    newdata->next=p->next;
    p->next=newdata;
  }

  void delete_ele(int a)
  {
    if(front->data == a)
    {
      delete_beg();
      return;
    }

    else if(rear->data == a)
    {
      delete_end();
      return;
    }

    node *p;

    p=front;

    while((p->next)->data != a)
    {
      p=p->next;
    }

    p->next=(p->next)->next;

  }

~Linkedlist()
  {
    while(front->next != NULL)
    {
      cout<<front->data<<"is destructed"<<endl;
      delete_beg();
    }
    delete_beg();
    delete front;
    delete rear;
  }
};

void ulta_traverse(Linkedlist l)
{
  Linkedlist newl;

  node *p;
  p=l.getfront();
  while(p->next != NULL)
  {
    newl.insert_beg2(p->data);
    p=p->next;
  }
  newl.insert_beg2(p->data);

  p=newl.getfront();
  while(p->next != NULL)
  {
    cout<<p->data<<"  ";
    p=p->next;
  }
  cout<<p->data<<endl;
}

int main()
{
  Linkedlist l;
  int choice, x, a;
  do
  {
      cout<<"1.insert begining"<<endl;
      cout<<"2.insert ending"<<endl;
      cout<<"3.delete begining"<<endl;
      cout<<"4.delete end"<<endl;
      cout<<"5.show data"<<endl;
      cout<<"7.insert after"<<endl;
      cout<<"8.insert before"<<endl;
      cout<<"9.delete particular element"<<endl;
      cout<<"10.ulta show"<<endl;
      cout<<"11.exit"<<endl;

      cout<<"enter choice"<<endl;
      cin>>choice;

      switch(choice)
      {
        case 1: l.insert_beg();
                break;
        case 2: cout<<"enter the element"<<endl;
                cin>>x;
                l.insert_end(x);
                break;
        case 3: l.delete_beg();
                break;
        case 4: l.delete_end();
                break;
        case 5: l.traverse();
                break;
        case 7: cout<<"enter the element after which you want to add"<<endl;
                cin>>a;
                l.insert_aft(a);
                break;
        case 8: cout<<"enter the element after which you want to add"<<endl;
                cin>>a;
                l.insert_bef(a);
                break;
        case 9: cout<<"enter the element you want to delete"<<endl;
                cin>>a;
                l.delete_ele(a);
                break;
        case 10: ulta_traverse(l);
                        break;

      }
  }while(choice != 11);

  return 0;
}
