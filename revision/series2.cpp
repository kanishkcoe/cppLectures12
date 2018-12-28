#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pyramidup(int n)
{
  int num = 1;
  for(int i=1; i<=n ; i++)
  {
    num = 1;
    for(int j=1; j<= i+n-1 ; j++)
    {
        if(i + j > n)
        {
          cout << num << "\t";
          if(j < n)
            num++;
          else
            num--;
        }
        else
        {
          cout << "\t";
        }

    }
    cout<<endl;
  }
}

int pyramiddown(int n)
{
  int num = 1;
  for(int i=1; i<=n ; i++)
  {
    num = 1;
    cout << "\t";
    for(int j=1 ; j<= 2 * n - i  ; j++)
    {
        if(j < i)
        {
          // cout << "*" << "\t";
          // cout << num << "\t";
          cout << "\t";
          // if(j > n)
          //   num--;
          // else
            // num++;
        }
        else if(j > n - 1 && j < 2 * n - i)
        {
          cout << num << "\t";
          num--;
        }
        else
        {

          cout << num << "\t";
          num++;
        }

    }
    cout<<endl;
  }
}

int main()
{
  for(int i = 0; i < 3; i++)
  {
    pyramidup(10);
    pyramiddown(9);    
  }

  return 0;
}
