#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long factorial(int x)
{
  long product = 1;

  for(int i = 1; i <= x; i++)
  {
    cout << product << " - ";
    product = product * i;
    //product *= i;
  }

  cout << endl;
  return product;
}


long fact(int x)
{
  //stopping condition
  if(x == 1)
    return 1;

  //recursive fashion
  return x * fact(x-1);
}
int main()
{
  int num;
  cout << "Enter the value = ";
  cin >> num;
  cout << "factorial of " << num << " is = " << fact(num) << endl;

  return 0;
}
