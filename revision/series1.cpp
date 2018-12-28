#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void series(int n)
{
  int a=1;

  for(int i=1 ; i<=n ; i++)
  {
    for(int j=1 ; j<=n ; j++)
    {
      if(j<=i)
      {
        cout<<a<<"\t";
        a++;
      }
      else
      {
        cout<<"*"<<"\t";
      }
    }
    cout<<endl;
  }
}

int main()
{
  series(5);

  return 0;
}
