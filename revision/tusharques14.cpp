#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binary_search(int arr[], int size , int ele)
{
  int l ,h,m ;
  l=0;
  h=size - 1;

  while(l <= h)
  {
    m = (l+h)/2;

    if(arr[m]==ele)
    {
      cout<<"the element is at : "<<m+1<<" position"<<endl;
      return m;
    }

    else if(arr[m]>ele)
    {
      h = m-1;
    }

    else
    {
      l = m+1;
    }
  }

  return -1;
}

int enter(int a[],int size)
{
  cout<<"enter array"<<endl;

  for(int i=0;i<size ; i++)
  {
    cin>>a[i];
  }

  return 0;
}

int main()
{
  int a[20],size,ele;
  cout<<"enter the size of array"<<endl;
  cin>>size;
  enter(a,size);
  cout<<"enter the element you want to search"<<endl;
  cin>>ele;
  binary_search(a,size,ele);

  return 0;
}
