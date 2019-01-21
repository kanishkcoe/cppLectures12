#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int &a,int &b)
{
  char temp;
  temp = a;
  a=b;
  b=temp;
}

void bubblesort(int a[],int size)
{
  for(int i=0 ; i < size ; i++)
  {
    for(int j =0 ; j<size-i;j++)
    {
      if(a[j]>a[j+1])
      {
        swap(a[j],a[j+1]);
      }
    }
  }

  for(int i=0 ; i < size ; i++)
  {
    cout<<a[i]<<"  "<<endl;
  }
}

void selectionsort(int a[] , int a)
{
  int min;
  for(int i = 0 ; i<a-1 ; i++)
  {
    min=i;
    for(int j = i+1 ; j<a-1 ; j++)
    {
      if(a[min]>a[j])
      {
        min =j;
      }

      swap(a[min],a[j]);
    }

  }
}

void print(int a[], int size)
{
  for()
}

void insertionsort(int a[],int a)
{
  int curr;
  for(int i=0; i<a ; i++)
  {
    curr = a[i];
  }
}

int main()
{


  return 0;
}
