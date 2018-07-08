#include <iostream>
#include <fstream>

using namespace std;

class Student
{
  int roll;
  char name[20];

public:

  void get()
  {
    cout << "Enter roll number : ";
    cin >> roll;
    cin.ignore();

    cout << "Enter the name : ";
    cin.getline(name, 20);
  }

  void show()
  {
    cout << "Roll number : " << roll << endl;
    cout << "Name : " << name << endl;
  }
};

class Marks
{
  int subject;
  char remark[20];

public:

  void get()
  {
    cout << "Enter Subject : ";
    cin >> subject;
    cin.ignore();

    cout << "Enter the Remark : ";
    cin.getline(remark, 20);
  }

  void show()
  {
    cout << "Subject : " << subject << endl;
    cout << "Remark : " << remark << endl;
  }
};

int main()
{


  return 0;
}
