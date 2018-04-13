#include <iostream>

using namespace std;

// returns whether one number divides another or not.
int divide(int, int);

//returns whether the number is prime or not.
int divide(int);

int main()
{
  int a, b;

  cout << "Enter numbers : " << endl;
  cin >> a >> b;

  cout << divide(a, b) << endl;
  cout << divide(a) << endl;

  return 0;
}

int divide(int a, int b)
{
  if(a % b == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int divide(int num)
{
  for(int i = 2; i <= num / 2; i++)
  {
    if(divide(num, i))
    {
      return 0;
    }
  }

  return 1;
}
