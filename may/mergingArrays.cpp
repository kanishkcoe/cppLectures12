#include <iostream>

using namespace std;

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


  return 0;
}
