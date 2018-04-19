#include <iostream>

using namespace std;

class School
{
protected:
  char name[20];
  int age;
  char address[50];
};

class Student : public School
{
  int standard;
  int roll_number;

public:
  void get_details();
  void show_details();
};

void Student::get_details()
{
  cout << "Enter roll number : "; cin >> roll_number;
  cin.ignore();
  cout << "Enter name : "; cin.getline(name, 20);
  cout << "Enter age : "; cin >> age;
  cout << "Enter standard : "; cin >> standard;
  cin.ignore();
  cout << "Enter address : "; cin.getline(address, 50);
}

void Student::show_details()
{
  cout << "Roll number : " << roll_number << endl;
  cout << "Name : " << name << endl;
  cout << "Standard : " << standard << endl;
  cout << "Age : " << age << endl;
  cout << "Address : " << address << endl;
}

int main()
{
  Student student;

  student.get_details();

  student.show_details();

  return 0;
}
