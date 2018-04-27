#include <iostream>

using namespace std;

class Person
{
  int age;
  char name[20];

public:
  void get();
  void show();
};

class Student : public Person
{
  int rollno;
  float average;

public:
  void insert();
  void display();
};

class GradStudent : public Student
{
  char subject[20];
  char working;

public:
  void enter();
  void displayDetails();
};


//function definitions
void Person::get()
{
  cin.ignore();
  cout << "Enter name : ";
  cin.getline(name, 20);

  cout << "Enter age : ";
  cin >> age;
}

void show()
{
  cout << "Name : " << name << endl;
  cout << "Age : " << age << endl;
}

void Student::insert()
{
  cout << "Enter roll number : ";
  cin >> rollno;

  cout << "Enter average : ";
  cin >> average;
}

void Student::display()
{
  cout << "Roll number : " << rollno << endl;
  cout << "Average : " << average << endl;
}

void GradStudent::enter()
{
  cin.ignore();
  cout << "Enter subject : ";
  cin.getline(subject, 20);

  cout << "Enter working status : ";
  cin >> working;
}

void GradStudent::displayDetails()
{
  cout << "Subject : " << subject << endl;
  cout << "Working : " << working << endl;
}

int main()
{


  return 0;
}
