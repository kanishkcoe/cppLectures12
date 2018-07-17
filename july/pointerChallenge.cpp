#include <iostream>

using namespace std;

int main()
{
  int arr[] = {10, 23, 30, 40};
  int *ptr = arr;
  int val = *ptr;
  cout << val << endl;
  val = *ptr++;
  cout << val << endl;
  val = *ptr;
  cout << val << endl;
  val = *++ptr;
  cout << val << endl;

  return 0;
}
