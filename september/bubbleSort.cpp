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


void ascBubbleSort(int a[], int size)
{
  for(int pass = 1; pass < size; pass++)
  {
    printArray(a, 0, size);
    for(int j = 0; j < size - pass; j++)
    {
      if(a[j] > a[j+1])
      {
        swap(a[j], a[j+1]);
      }
    }
  }
}

void descBubbleSort(int a[], int size)
{
  for(int pass = 1; pass < size; pass++)
  {
    printArray(a, 0, size);
    for(int j = 0; j < size - pass; j++)
    {
      if(a[j] < a[j+1])
      {
        swap(a[j], a[j+1]);
      }
    }
  }
}

int main()
{

  int a[] = {8, 1, 3, 0, 6, 9, 2};
  int size = sizeof(a) / sizeof(a[0]);

  descBubbleSort(a, size);
  return 0;
}
