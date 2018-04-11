#include <iostream>
#include <math.h>

using namespace std;

int area(int a)
{
  return a * a;
}

int area(int a, int b)
{
  return a * b;
}

double area(double r)
{
  return 3.14 * r * r;
}

double area(int a, int b, int c)
{
    double s = double((a + b + c) / 2);
    double term = (s * (s - a) * (s - b) * (s - c));
    return sqrt(term);
}

int main()
{
  int a;
  float b;
  //area of a square
  cin >> a;
  cout << area(5) << endl;

  //area of rectangle
  cout << area(10, 20) << endl;

  //area of circle
  cin >> b;
  cout << area(5.0) << endl;

  //area of triangle
  cout << area(30, 51, 40) << endl;

  return 0;
}
