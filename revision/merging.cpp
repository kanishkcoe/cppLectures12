#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void show(int a[], int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

void merge(int a[], int asize, int b[], int bsize, int c[])
{
  int i = asize - 1;  //a index indicator
  int j = bsize - 1 ;  //b index indicator
  int k = 0;  //c index indicator

  //considering a and b are in ascending and c is also ascending

  //compare and fill
  while(i >= 0 && j >= 0)
  {
    if(a[i] > b[j])
    {
      c[k++] = a[i--];
    }
    else
    {
      c[k++] = b[j--];
    }
  }

  //if any of the array element remains

  //element from array a remains
  while(i >= 0)
  {
    c[k++] = a[i--];
  }


  //element from array b remains
  while(j >= 0)
  {
    c[k++] = b[j--];
  }

}


int main()
{
  int a[10] = {0, 2, 4, 6, 8, 10, 21, 24, 65, 99};
  int b[5] = {1, 7, 35, 54, 69};
  int c[15];

  show(a, 10);

  show(b, 5);

  merge(a, 10, b, 5, c);

  show(c, 15);

  return 0;
}
