#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 10

void inputArray(int a[MAX][MAX], int n, int m)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
}

void printArray(int a[MAX][MAX], int n, int m)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
}

void multiply(int a[MAX][MAX], int m, int n, int b[MAX][MAX], int p, int q, int c[MAX][MAX])
{
  int sum = 0;
  if(n != p)
  {
    cout << "Not possible." << endl;
    return;
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < q; j++)
    {
      sum = 0;
      for(int k = 0; k < n; k++)
      {
        sum += a[i][k] * b[k][j];
      }
      c[i][j] = sum;
    }
  }
}
int main()
{


  return 0;
}
