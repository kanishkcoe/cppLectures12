#include <iostream>
#include <fstream>

using namespace std;

class Test
{
  int a;
  char name[20];

public:
  void get()
  {
    cout << "Enter a : ";
    cin >> a;

    cin.ignore();

    cout << "Enter name : ";
    cin.getline(name, sizeof(name));
  }

  void show()
  {
    cout << a << " --- " << name << endl;
  }
};


int main()
{

  Test test;
  // test.get();
  // cout << "Enter name : ";
  // cin.getline(name, sizeof(name));
  //
  // // writing file
  // ofstream fout;
  // fout.open("test.txt", ios::out);
  //
  // fout.write((char *) &test, sizeof(test));
  //
  // fout.close();

  //reading file
  ifstream fin;

  fin.open("test.txt", ios::in);

  fin.read((char *) &test, sizeof(test));

  test.show();

  fin.close();
  return 0;
}
