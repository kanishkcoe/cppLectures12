#include <iostream>

using namespace std;

class Test
{
  int a;
  char b;
  static int count;

public:
  Test();
  Test(int, char);
  ~Test();
  static void showCount()
  {
    cout << "Count = " << count << endl;
  }
};

int Test::count = 0;

Test::Test()
{
  //default constructor
  a = 0;
  b = 'k';
  cout << a << " ---> " << b << endl;
  cout << "default constructor called." << endl;
  count++;
}

Test::Test(int num, char ch)
{
  a = num;
  b = ch;
  cout << a << " ---> " << b << endl;
  cout << "parameterised constructor called." << endl;
  count++;
}


Test::~Test()
{
  cout << a << " ---> " << b << endl;
  cout << "Destructor called." << endl;
  count--;
}


int main()
{
  Test obj;  //default constructor called
  obj.showCount();
  Test obj2(12, 'a'); //implicit called parameterised constructor
  obj2.showCount();
  Test obj3;
  obj3.showCount();
  obj3 = Test(65, 'e'); //explicit called parameterised constructor
  obj3.showCount();
  Test obj4 = Test(56, 'g');
  obj4.showCount();
  return 0;
}
