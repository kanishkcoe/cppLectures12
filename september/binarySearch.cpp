#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int a[], int start, int end)
{
  cout << "-----------------------------------------------" << endl;
  for(int i = start; i <= end; i++)
    cout << a[i] << " ";
  cout << endl;
  cout << "-----------------------------------------------" << endl;

}

int bsearch(int a[], int size, int e)
{
    int l = 0;
    int h = size - 1;
    int mid;
    cout << "size = " << size << endl;

    while(l <= h)
    {
      printArray(a, l, h);
      mid = (l + h) / 2;

      cout << endl << mid << " - > " << a[mid] << endl;

      if(a[mid] == e)
        return mid;

      else if(a[mid] < e)
        l = mid + 1;

      else
        h = mid - 1;
    }

    return -1;
}


int main()
{
  int a[] = {0, 1, 2, 3, 4, 7, 89, 456, 553, 2354, 10023};
  int size = sizeof(a) / sizeof(a[0]);

  cout << endl << bsearch(a, size, 456) << endl;

  return 0;
}
