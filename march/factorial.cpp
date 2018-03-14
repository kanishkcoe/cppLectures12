#include <iostream>

using namespace std;

int factorial(int n)
{
  //base conditions
  if(n == 1)
    return 1;

  // recursion fashion
  return n * factorial(n - 1);
}

int main()
{
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    cout << factorial(i) << endl;
  }

  return 0;
}
