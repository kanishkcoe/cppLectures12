#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int fibonacci(int n)
// {
//   if(n == 1)
//     return 0;
//
//   if (n == 2)
//     return 1;
//
//   int sum = 0;
//   int first = 0;
//   int second = 1;
//
//   for(int i = n; i >= 3; i--)
//   {
//       sum = first + second;
//       first = second;
//       second = sum;
//   }
//
//   return sum;
// }
int fibonacci(int n)
{
  if(n == 1)
    return 0;

  if (n == 2)
    return 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

  cout << "fibonacci sequence upto 12 terms : " << endl;

  for(int i = 1; i <= 12; i++)
  {
    cout << fibonacci(i) << ", ";
  }

  cout << endl;

  return 0;
}
