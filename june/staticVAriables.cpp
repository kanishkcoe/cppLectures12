#include <iostream>

using namespace std;

class Test
{
  int a, b, c;
  static int count;

public:
  Test(int k, int l, int h)
  {
    a = k;
    b = l;
    c = h;
  }

  void show()
  {
    cout << a << " " << b << " " << c << endl;
  }

  static void showCount()
  {
    count++;
    cout << count << endl;
  }
};

int Test::count;

int main()
{
  Test t1(123, 32, 546);
  t1.show();
  t1.showCount();

  Test t2(45, 546, 68);
  t2.show();
  t2.showCount();

  Test t3(45, 546, 68);
  t2.show();
  t2.showCount();
  return 0;
}
