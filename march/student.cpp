#include <iostream>

using namespace std;

struct DOB
{
  int date;
  int month;
  int year;
};

class Student
{
private:
  int rollno;
  char name[20];
  float marks[5];
  DOB dob;
  float avg;
  void calAvg();

public:
  void getDetails();
  void ShowDetails();
  float getAvg()
  {
    return avg;
  }
};

void printPassed(Student *, int);

int main()
{
  Student student[3];

  for(int i = 0; i < 3; i++)
  {
    student[i].getDetails();
  }

  printPassed(student, 3);

  return 0;
}

void Student::calAvg()
{
  float sum = 0;

  for(int i = 0; i < 5; i++)
  {
    sum += marks[i];
  }

  avg = sum / 5;
}

void Student::getDetails()
{
  char buffer;
  cout << "Enter the roll number : "; cin >> rollno;
  cin.ignore();
  cout << "Enter name : "; gets(name);
  cout << "DOB : "; cin >> dob.date >> dob.month >> dob.year;  //cascading input
  cout << "Enter marks : " << endl;
  for(int i = 0; i < 5; i++)
  {
    cout << "Subject " << i + 1 << " = ";
    cin >> marks[i];
  }

  calAvg();
}

void Student::ShowDetails()
{
  cout <<"-----------------------------------------------------" << endl;
  cout << "Roll number : " << rollno << endl;
  cout << "Name : " << name << endl;
  cout << "DOB : " << dob.date << "/" << dob.month << "/" << dob.year << endl;
  cout << "Average : " << avg << endl;
}

//normal function
void printPassed(Student *student, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(student[i].getAvg() > 36)
    {
      student[i].ShowDetails();
    }
  }
}
