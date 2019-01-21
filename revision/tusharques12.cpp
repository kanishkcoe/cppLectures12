#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merging(int a[], int p, int b[], int q, int c[])
{
  int i=0;
  int j=0;
  int k=0;

  while(i<p && j<q)
  {
    if(a[i] <= b[j])
    {
     c[k++] = a[i++];
    }

    else
    {
      c[k++] = b[j++];
    }
  }

  while(i<p)
  {
    c[k++] = a[i++];
  }

  while(j<q)
  {
    c[k++] = b[j++];
  }

  for( int s=0 ; s<k ;s++ )
  {
    cout<<c[s]<<"  ";
  }
}

void input(int a[], int x)
{
  cout<<"enter array"<<endl;
  for(int i = 0 ; i<x ;i++)
  {
    cin>>a[i];
  }
}

int main()
{
  int a[10],p,b[10],q,c[10];
  cout<<"enter size"<<endl;
  cin>>p;
  input(a ,p);

  cout<<"enter size"<<endl;
  cin>>q;
  input(b ,q);

  merging(a,p,b,q,c);

  return 0;
}
