#include <iostream>
#include <bits/stdc++.h>

using namespace std;



class Student
{
  char name[20];
  int roll;
  float marks[5]; //array within a class
  float average() const;  //mutator functions
  static int count;

public:

  //manager functions
  Student()
  {
    strcpy(name, "None");
    roll = 0;
    for(int i = 0; i < 5; i++)
      marks[i] = 0;
  }

  Student(char name[20], int roll, float marks[5], int day, int month, int year)
  {
    strcpy(this->name, name);
    this->roll = roll;
    for(int i = 0; i < 5; i++)
      this->marks[i] = marks[i];
  }

  Student(Student &object)
  {
    strcpy(this->name, object.name);
    this->roll = object.roll;
    for(int i = 0; i < 5; i++)
      this->marks[i] = object.marks[i];
  }

  void get(); //accessor functions
  void show();

  void showCount()
  {
    cout << "Count is " << count << endl;
  }
};

int Student::count = 0;
float Student::average() const
{
  float sum = 0;
  for(int i = 0; i < 5; i++)
    sum += marks[i];

  return sum / 5;
}

void Student::get()
{
  cout << "Enter roll number : ";
  cin >> roll;

  cin.ignore();
  cout << "Enter name : ";
  cin.getline(name, 20);

  cout << "Enter marks for : " << endl;

  for (int i = 0; i < 5; i++)
  {
    cout << "Subject " << i + 1 << " : ";
    cin >> marks[i];
  }
  count++;
}

void Student::show()
{
  cout << "roll number : ";
  cout << roll;
  cout << endl;

  cout << "name : ";
  cout << name;
  cout << endl;

  cout << "marks for : " << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "Subject " << i + 1 << " : ";
    cout << marks[i];
    cout << endl;
  }

  cout << "Average : " << average() << endl;
}

void hoolalala(Student student[], int n)
{
  cout << "details of students : " << endl;
  for(int i = 0; i < n; i++)
  {
    student[i].show();
  }
}

int main()
{
  int n;

  cout << "Enter number of students : ";
  cin >> n;

  Student student[n];

  cout << "Enter details of students : " << endl;
  for(int i = 0; i < n; i++)
  {
    student[i].get();
    student[i].showCount();
  }

  hoolalala(student, n);

  return 0;
}
