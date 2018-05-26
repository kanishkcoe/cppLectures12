#include <iostream>

using namespace std;

void printArray(int *a, int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << a[i] << ", ";
  }

  cout << "!!!" << endl;
}

void merge(int *a, int a_size, int *b, int b_size, int *c, int c_size)
{
  int i;  //array a index
  int j;  //array b index
  int k;  //array c index

  i = j = k = 0;  //chain initialisation

  //compare elements from a and b
  //assign required value
  //change the index of the respective array

  while(i < a_size && j < b_size)
  {
    if(a[i] <= b[j])
    {
      c[k] = a[i];
      i++;
    }
    else
    {
      c[k] = b[j];
      j++;
    }
    k++;
  }

  //when array b is finished
  //insert all elements of a
  while(j >= b_size && i < a_size)
  {
    c[k] = a[i];
    i++;
    k++;
  }

  //when array a is finished
  //insert all elements of b
  while(j < b_size && i >= a_size)
  {
    c[k] = b[j];
    j++;
    k++;
  }
}

int main()
{
  int a[] = {1, 3, 5, 9};
  int b[] = {2, 4, 6, 7, 8, 9, 10};
  int c[11];

  int a_size = 4;
  int b_size = 7;
  int c_size = a_size + b_size;

  merge(a, a_size, b, b_size, c, c_size);

  printArray(a, a_size);
  printArray(b, b_size);
  printArray(c, c_size);

  return 0;
}
