#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct book
{
  int bookno;
  int price;
  char title[20];
  char subject[20];
  book *next;
};

class Linkedlist
{
  book *front;
  book *rear;

public:

  Linkedlist()
  {
    front = NULL;
    rear = NULL;
  }

  void add()
  {
    int b,p;
    char t[20],s[20];

    cout<<"enter book  no:"<<endl;
    cin>>b;
    cout<<"enter price"<<endl;
    cin>>p;
    cout<<"enter title"<<endl;
    cin.ignore();
    cin.getline(t,sizeof(t));

    cout<<"enter subject"<<endl;
    cin.ignore();
    cin.getline(s,sizeof(s));

    book *temp;
    temp = new book;
    temp->bookno=b;
    temp->price=p;
    strcpy(temp->title,t);
    strcpy(temp->subject,s);
    temp->next =NULL;

    if(front == NULL && rear == NULL)
    {
      front =  temp;
      rear = temp;
      return;
    }

    temp->next=front;
    front =temp;

  }

  void search()
  {
    int x,b;
    char sub[20];
    cout<<"1.by subject"<<endl;
    cout<<"2.by book no"<<endl;
    cout<<"enter your choice "<<endl;
    cin>>x;

    if(x==1)
    {
      cout<<"enter subject"<<endl;
      cin.ignore();
      cin.getline(sub,sizeof(sub));
      book *p;
      p= front;
      while(p!=NULL)
      {
        if(strcmp(p->subject,sub)==0)
        {
          cout<<"book no: "<<p->bookno<<endl;
          cout<<"price : "<<p->price<<endl;

          cout<<"title : "<<p->title<<endl;

          cout<<"subject : "<<p->subject<<endl;

        }
        p=p->next;
      }
    }
    else
    {
      cout<<"enter bookno"<<endl;
      cin>>b;
      book *p;
      p= front;
      while(p!=NULL)
      {
        if(p->bookno==b)
        {
          cout<<"book no: "<<p->bookno<<endl;
          cout<<"price : "<<p->price<<endl;

          cout<<"title : "<<p->title<<endl;

          cout<<"subject : "<<p->subject<<endl;

        }
        p=p->next;
      }
    }
  }

  void show()
  {
    book *p;
    p= front;
    while(p!=NULL)
    {

        cout<<"book no: "<<p->bookno<<endl;
        cout<<"price : "<<p->price<<endl;

        cout<<"title : "<<p->title<<endl;

        cout<<"subject : "<<p->subject<<endl;

        p=p->next;
    }
  }
};

int main()
{
  int x;
  Linkedlist l;

do
{
  cout<<"1.add data"<<endl;
  cout<<"2.search"<<endl;
  cout<<"3.show"<<endl;
  cout<<"4.exit"<<endl;

  cout<<"enter choice"<<endl;
  cin>>x;

  switch(x)
  {
    case 1: l.add();
              break;

    case 2:l.search();
            break;

    case 3:l.show();
            break;
  }
}while(x!=4);
  return 0;
}
