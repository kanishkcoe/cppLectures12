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
  //constructors
  //default constructors
  Complex()
  {
    real = 10;
    imaginary = 40;
  }

  //parameterised constructors
  Complex(int r, int i)
  {
    real = r;
    imaginary = i;
  }

  //copy constructors
  Complex(Complex &s)
  {
    real = s.imaginary;
    imaginary = s.real;
  }

  Complex(Complex &s, Complex &k)
  {
    real = s.real + k.real;
    imaginary = s.imaginary + k.imaginary;
  }

  //destructor
  ~Complex()
  {
    cout << "---------------------------------" << endl;
    cout << real << " i" << imaginary << endl;
    cout << "destructor called saksham" << endl;
    cout << "---------------------------------" << endl;
  }
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
  Complex e, f(45, 100);
  Complex g(f);
  Complex h = c;
  Complex k(f, g);
  c.set(3, 5);
  d.set(5, -56);

  c.get();
  cout << endl;
  d.get();
  cout << endl;
  e.get();
  cout << endl;
  f.get();
  cout << endl;
  g.get();
  cout << endl;
  h.get();
  cout << endl;
  k.get();
  cout << endl;
  return 0;
}
