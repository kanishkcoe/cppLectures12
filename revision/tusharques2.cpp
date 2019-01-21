#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Vector
{
  int vector[100];
  int size;

public:

  void creation()
  {
    cout<<"enter the size of vector : ";
    cin>>size;
    cout<<"enter the vector : ";
    for(int i=0 ; i<size ; i++)
    {
      cin>>vector[i];
    }
  }

  void modification(int element)
  {
    int ele;
    for(int i=0 ; i<size ;i++)
    {
      if(vector[i] == element)
      {
        cout<<"enter the new element : ";
        cin>>ele;
        vector[i] = ele;
      }
    }
  }

  void largest()
  {
    int temp = vector[0];
    for(int i=0 ; i<size ; i++)
    {
      if(vector[i] > temp)
      {
        temp = vector[i];
      }
    }
  cout<<"the largest element : "<<temp<<endl;
  }

  void display()
  {
    for (int i=0 ; i<size ; i++)
    {
      cout<<vector[i]<<" ";
    }
    cout<<endl;
  }

};

int main()
{
  Vector v;
  v.creation();
  v.modification(6);
  v.largest();
  v.display();


  return 0;
}
