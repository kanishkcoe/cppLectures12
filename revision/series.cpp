#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int power(int base, int exponent)
{
  if(exponent == 1)
    return base;

  return base * power(base, exponent - 1);
}

long factorial(int x)
{
  //stopping condition
  if(x == 1)
    return 1;

  //recursive fashion
  return x * factorial(x-1);
}

float series_sum(int x, int n)
{
  float sum = 0;
  for(int i = 1; i <= n; i++)
  {
    sum += (float)power(x, i) / float(factorial(i));
  }

  return sum;
}

int main()
{

  int x, n;

  cout << "Enter x and n : " << endl;
  cout << "x = "; cin >> x;
  cout << "n = "; cin >> n;

  cout << "series_sum is = " << series_sum(x, n) << endl;
  return 0;
}
