#include <iostream>

using namespace std;

int fibonacci(int n)
{
  //base conditions
  if(n == 1)
    return 0;
  if(n == 2)
    return 1;

  // recursion fashion
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    cout << fibonacci(i) << endl;
  }

  return 0;
}
