#include <iostream>

using namespace std;

//class definition
class Complex
{
  //private members
private:
  int real;
  int imaginary;

  //public:
public:
  void set(int r, int i)
  {
    real = r;
    imaginary = i;
  }

  void get()
  {
    cout << real << " + i(" << imaginary << ")";
  }
};

int main()
{
  Complex c, d;
  c.set(3, 5);
  d.set(5, -56);

  c.get();
  cout << endl;
  d.get();
  cout << endl;
  return 0;
}
