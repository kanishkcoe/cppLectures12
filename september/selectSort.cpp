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


void ascendingSelectionSort(int a[], int size)
{
  int min = 0;  //index of the minimum element

  for(int i = 0; i < size; i++)
  {
    printArray(a, 0, size);

    min = i;

    for(int j = i + 1; j < size; j++)
    {
      if(a[min] >= a[j])
      {
        min = j;
      }
    }

    swap(a[min], a[i]);
  }
  printArray(a, 0, size);

}

void descendingSelectionSort(int a[], int size)
{
  int max = 0;  //index of the minimum element

  for(int i = 0; i < size; i++)
  {
    printArray(a, 0, size);
    max = i;

    for(int j = i + 1; j < size; j++)
    {
      if(a[max] < a[j])
      {
        max = j;
      }
    }

    swap(a[max], a[i]);
  }
  printArray(a, 0, size);
}

int main()
{

  int a[] = {9, 8, 1, 0, 9, 1, 0, 4, 9, 2, 8, 1, 3, 0, 6, 9, 2, 8, 4, 3};
  int size = sizeof(a) / sizeof(a[0]);

  descendingSelectionSort(a, size);
  return 0;
}
