#include <iostream>
#include <math.h>

using namespace std;

int area(int side)
{
  return side * side;
}

int area(int length, int bredth)
{
  return length * bredth;
}

double area(double radius)
{
  return 3.14 * radius * radius;
}

double area(int a, int b, int c)
{
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
  //square's area
  cout << area(41) << endl;

  //rectangle's area
  cout << area(12, 5) << endl;

  //circle's area
  cout << area(1) << endl;

  //triangle's area
  cout << area(3, 4, 5) << endl;

  return 0;
}
