#include <iostream>

using namespace std;

class Base
{
  int a, b;

public:
  void get();
  void show();
};

class Derived : public Base
{
  int c, d;

public:
  // void insert();
  // void display();
  void fun()
  {
    cout << "jai mata di" << endl;
  }
};

void Base::get()
{
  cout << "Base get function called !" << endl;
  cout << "a : "; cin >> a;
  cout << "b : "; cin >> b;
}

void Base::show()
{
  cout << "Base show function called !" << endl;
  cout << "a : " << a << endl;
  cout << "b : " << b << endl;
}

// void Derived::insert()
// {
//   cout << "Derived insert function called !" << endl;
//   cout << "c : "; cin >> c;
//   cout << "d : "; cin >> d;
// }
//
// void Derived::display()
// {
//   cout << "Derived display function called !" << endl;
//   cout << "c : " << c << endl;
//   cout << "d : " << d << endl;
// }

int main()
{
  Base b;
  Derived d;

  b.get();
  b.show();

  d.get();
  d.show();
  d.fun();

  return 0;
}
