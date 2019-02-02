#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print(int a[], int size)
{
  for(int i=0 ; i<size ;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a,int &b)
{
  int temp;
  temp = a;
  a=b;
  b=temp;
}

void enteraraay(int a[], int size)
{
  for(int i=0 ; i<size ;i++)
  {
    cin>>a[i];
  }
}

void bubblesort(int a[],int size)
{
  for(int i=0 ; i < size ; i++)
  {
    cout<<"after pass "<<i+1<<endl;
    print(a,size);
    for(int j =0 ; j<size-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        swap(a[j],a[j+1]);
      }
    }
  }

}

void selectionsort(int a[] , int n)
{
  int min;
  for(int i = 0 ; i<n ; i++)
  {
    cout<<"after pass "<<i+1<<endl;
    print(a,n);
    min=i;
    for(int j = i+1 ; j<n ; j++)
    {
      if(a[min]>a[j])
      {
        min =j;
      }

    }
    swap(a[min],a[i]);

  }
}


void insertionsort(int a[],int n)
{
  int curr , j;
  for(int i=1; i<n ; i++)
  {
    j=i-1;
    curr = a[i];
    cout<<"after pass "<<i<<endl;
    print(a,n);

    while(a[j]>curr)
    {
      a[j+1] = a[j];
      j--;
      //cout<<j<<endl;
    }

    a[j+1]=curr;

  }
}

int main()
{
  int n;

  int a[20],size;
  cout<<"enter the size of array"<<endl;
  cin>>size;
  cout<<"enter array"<<endl;

  enteraraay(a,size);
do
{
  cout<<"1.bubble sort"<<endl;
  cout<<"2.selection sort"<<endl;
  cout<<"3.insertion sort"<<endl;
  cout<<"4.show"<<endl;
  cout<<"5.exit"<<endl;

  cout<<"enter choice"<<endl;
  cin>>n;

  switch(n)
  {
    case 1:bubblesort(a,size);
            break;
    case 2:selectionsort(a,size);
            break;
    case 3: insertionsort(a,size);
            break;
    case 4:print(a,size);
            break;
  }

}while(n!=5);

  return 0;
}
