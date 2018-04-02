#include <iostream>

using namespace std;

class Student
{
private:
  int rollno;
  char name[20];
  float marks[5];
  char grade();

public:
  void get_data();
  void show_data();
};

char Student::grade()
{
  float avg = 0.0;
  for(int i = 0; i < 5 ; i++)
  {
    avg += marks[i];
  }

  avg /= 5.0;

  if(avg <= 30)
    return 'F';
  else if(avg <= 50)
    return 'E';
  else if(avg <= 60)
    return 'D';
  else if(avg <= 70)
    return 'C';
  else if(avg <= 80)
    return 'B';
  else if(avg <= 90)
    return 'A';
  else if(avg <= 100)
    return 'O';
  else
    return '~';
}

void Student::get_data()
{
  cout << "Enter roll number : "; cin >> rollno;
  cin.ignore();
  cout << "Enter name : "; cin.getline(name, 20);
  cout << "Enter marks : " << endl;
  for(int i = 0 ; i < 5; i++)
  {
    cout << "marks " <<  i + 1 << " : ";
    cin >> marks[i];
  }
}

void Student::show_data()
{
  cout << "Roll number : " << rollno << endl;
  cout << "Name : " << name << endl;
  cout << "Grade : " << grade() << endl;
}

int main()
{

  Student student[5];

  for(int i = 0; i < 5; i++)
  {
    student[i].get_data();
  }

  for(int i = 0; i < 5; i++)
  {
    student[i].show_data();
  }
  return 0;
}
