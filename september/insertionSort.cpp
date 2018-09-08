#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int a[], int start, int end)
{
  cout << "-----------------------------------------------" << endl;
  for(int i = start; i < end; i++)
    cout << a[i] << " ";
  cout << endl;
  cout << "-----------------------------------------------" << endl;

}


void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void ascInsertionSort(int a[], int size)
{
  for(int i = 1; i <= size; i++)
  {
    printArray(a, 0, size);
    for(int j = 0; j <= i; j++)
    {
      if(a[j] > a[i])
      {
        swap(a[j], a[i]);
      }
    }
  }
}

void descInsertionSort(int a[], int size)
{
  for(int i = 1; i <= size; i++)
  {
    printArray(a, 0, size);
    for(int j = 0; j <= i; j++)
    {
      if(a[j] < a[i])
      {
        swap(a[j], a[i]);
      }
    }
  }
}

int main()
{

  int a[] = {INT_MAX, 9, 8, 1, 0, 9, 1, 0, 4, 9, 2, 8, 1, 3, 0, 6, 9, 2, 8, 4, 3};
  int size = sizeof(a) / sizeof(a[0]);

  descInsertionSort(a, size);
  return 0;
}
